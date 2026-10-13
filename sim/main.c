/**
 * @file main.c
 *
 * PC simulator entry point for a UI exported from LVGL Pro: opens a window,
 * initializes the exported UI library and starts the LVGL loop.
 */

/* Built only by sim/CMakeLists.txt; lets a glob-based embedded build skip it. */
#ifdef LVGL_PRO_SIMULATOR_BUILD

#include "lvgl.h"
#include "hal.h"
#include UI_HEADER   /* exported UI library: header, UI_INIT and size come from
                        project.xml via sim/CMakeLists.txt */

/* Screen navigation: home <-> settings. Both screens are permanent (their
 * create() returns the same instance), so navigation just flips between them
 * with an animated load. */
static lv_obj_t * home_screen = NULL;
static lv_obj_t * settings_screen = NULL;

static void go_home(void)
{
    /* Swipe up: the settings curtain lifts up with the finger, home is the
     * static backdrop (single-tree render, cheap on MCU) */
    lv_screen_load_anim(home_screen, LV_SCREEN_LOAD_ANIM_OUT_TOP, 300, 0, false);
}

static void go_settings(void)
{
    /* Pull down: the settings curtain drops over the static home.
     * Note: LVGL names these enums by motion direction, so "dropping in
     * from the top" is OVER_BOTTOM (y: -h -> 0), not OVER_TOP. */
    lv_screen_load_anim(settings_screen, LV_SCREEN_LOAD_ANIM_OVER_BOTTOM, 300, 0, false);
}

static void home_gesture_cb(lv_event_t * e)
{
    /* Pull down on home opens settings */
    LV_UNUSED(e);
    if(lv_indev_get_gesture_dir(lv_indev_active()) == LV_DIR_BOTTOM) go_settings();
}

static void settings_gesture_cb(lv_event_t * e)
{
    /* Swipe up on settings returns home */
    LV_UNUSED(e);
    if(lv_indev_get_gesture_dir(lv_indev_active()) == LV_DIR_TOP) go_home();
}

/* Infinite carousel: three fixed slots host the faces; after every snap the
 * face trees are re-parented so the center slot always shows the logical
 * page and both neighbors stay pre-filled. Swiping past an edge wraps. */
static lv_obj_t * slots[3];   /* page_left / page_center / page_right */
static lv_obj_t * faces[3];   /* faces[0]=dial, [1]=health, [2]=weather */
static int32_t cur_page = 0;  /* logical page shown in the center slot */
static bool cycling = false;  /* guards against the recenter's own events */

/* Move the face trees so left=p-1, center=p, right=p+1 (all mod 3), then
 * silently re-center the pager on the middle slot. */
static void refill_slots(lv_obj_t * pager, int32_t p)
{
    int32_t want[3] = { (p + 2) % 3, p, (p + 1) % 3 };   /* left, center, right */
    cycling = true;
    for(int32_t s = 0; s < 3; s++) {
        lv_obj_t * face = faces[want[s]];
        if(lv_obj_get_parent(face) != slots[s]) lv_obj_set_parent(face, slots[s]);
    }
    lv_obj_scroll_to_x(pager, UI_WIDTH, LV_ANIM_OFF);
    cycling = false;
}

/* Live page-dots feedback while dragging. */
static void pager_scroll_cb(lv_event_t * e)
{
    lv_obj_t * pager = lv_event_get_target(e);
    int32_t slot = (lv_obj_get_scroll_x(pager) + UI_WIDTH / 2) / UI_WIDTH;   /* 0/1/2 */
    int32_t page = cur_page + (slot - 1);
    if(page < 0) page = 0;
    if(page > 2) page = 2;
    lv_subject_set_int(&subject_page, page);
}

/* After every snap: advance the logical page and rotate the slots. */
static void pager_scroll_end_cb(lv_event_t * e)
{
    if(cycling) return;
    lv_obj_t * pager = lv_event_get_target(e);
    int32_t slot = (lv_obj_get_scroll_x(pager) + UI_WIDTH / 2) / UI_WIDTH;   /* 0/1/2 */
    if(slot == 1) return;                    /* settled on center: nothing to cycle */
    cur_page = (cur_page + (slot - 1) + 3) % 3;
    refill_slots(pager, cur_page);
    lv_subject_set_int(&subject_page, cur_page);
}

/* Advances the clock subjects once per second (simulated RTC starting 07:30).
 * On hardware, replace the body with RTC/sensor reads - the UI binds the same
 * subjects either way. */
static void clock_tick_cb(lv_timer_t * timer)
{
    LV_UNUSED(timer);
    static int32_t elapsed = 0;
    elapsed = (elapsed + 1) % 86400;   /* wraps at 24 h */

    int32_t total_min = 7 * 60 + 30 + elapsed / 60;   /* fake start 07:30 */
    int32_t hh = (total_min / 60) % 24;
    int32_t mm = total_min % 60;

    lv_subject_snprintf(&subject_time, "%02d:%02d", (int)hh, (int)mm);
    lv_subject_set_int(&subject_seconds, elapsed % 60);
}

int main(void)
{
    lv_init();

    /* Create the display BEFORE taking the LVGL mutex: the Windows driver's
     * window procedure takes the same mutex to handle WM_CREATE, so holding
     * it here would deadlock window creation. */
    hal_init(UI_WIDTH, UI_HEIGHT);

    /* Hold the LVGL mutex while building the UI: a no-op without an OS, but
     * required to stay off the Windows driver's render thread. */
    lv_lock();

    UI_INIT("A:");      /* "A:" = file-system drive for file-based assets */

    /* Create the watch screens and wire up navigation */
    home_screen = screen_home_create();
    settings_screen = screen_settings_create();

    /* Carousel wiring: cache slots/faces, then the scroll handlers */
    slots[0] = lv_obj_find_by_name(home_screen, "page_left");
    slots[1] = lv_obj_find_by_name(home_screen, "page_center");
    slots[2] = lv_obj_find_by_name(home_screen, "page_right");
    faces[2] = lv_obj_get_child(slots[0], 0);   /* weather starts on the left */
    faces[0] = lv_obj_get_child(slots[1], 0);   /* dial starts in the center */
    faces[1] = lv_obj_get_child(slots[2], 0);   /* health starts on the right */

    lv_obj_t * pager = lv_obj_find_by_name(home_screen, "pager");
    if(pager) {
        lv_obj_add_event_cb(pager, pager_scroll_cb, LV_EVENT_SCROLL, NULL);
        lv_obj_add_event_cb(pager, pager_scroll_end_cb, LV_EVENT_SCROLL_END, NULL);
    }

    /* Gesture navigation: pull down on home opens, swipe up on settings closes */
    lv_obj_add_event_cb(home_screen, home_gesture_cb, LV_EVENT_GESTURE, NULL);
    lv_obj_add_event_cb(settings_screen, settings_gesture_cb, LV_EVENT_GESTURE, NULL);

    lv_screen_load(home_screen);

    lv_unlock();

    lv_timer_create(clock_tick_cb, 1000, NULL);

    while(1) {
        uint32_t idle_ms = lv_timer_handler();
        if(idle_ms == LV_NO_TIMER_READY) idle_ms = LV_DEF_REFR_PERIOD;
        lv_sleep_ms(idle_ms);
    }

    return 0;
}

#endif /*LVGL_PRO_SIMULATOR_BUILD*/
