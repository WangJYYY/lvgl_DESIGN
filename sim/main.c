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

    /* Load a screen from your project */

    lv_screen_load(screen_components_create());

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
