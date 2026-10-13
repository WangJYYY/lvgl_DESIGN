/**
 * @file screen_home_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_home_gen.h"
#include "../../lvgl_ui_project.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_home_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`screen_home` is already initialized as a permanent screen. Returning with no change.");
        return screen_home;
    }

    static lv_style_t style_dot_active;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_dot_active);

        lv_style_set_bg_color(&style_dot_active, COLOR_DATA);
        lv_style_set_bg_opa(&style_dot_active, (255 * 100 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        screen_home = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = screen_home;
        lv_obj_set_name_static(lv_obj_0, "screen_home_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x000000), 0);
        lv_obj_set_style_radius(lv_obj_0, 233, 0);
        lv_obj_set_style_clip_corner(lv_obj_0, true, 0);

        lv_obj_t * bezel = lv_obj_create(lv_obj_0);
        lv_obj_set_name(bezel, "bezel");
        lv_obj_set_width(bezel, 466);
        lv_obj_set_height(bezel, 466);
        lv_obj_set_flag(bezel, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_bg_opa(bezel, (255 * 0 / 100), 0);
        lv_obj_set_style_border_width(bezel, 4, 0);
        lv_obj_set_style_border_color(bezel, lv_color_hex(0x04ff00), 0);
        lv_obj_set_style_radius(bezel, 233, 0);
        lv_obj_set_style_clip_corner(bezel, true, 0);
        lv_obj_t * pager = lv_obj_create(bezel);
        lv_obj_set_name(pager, "pager");
        lv_obj_set_width(pager, 466);
        lv_obj_set_height(pager, 466);
        lv_obj_set_flag(pager, LV_OBJ_FLAG_SCROLLABLE, true);
        lv_obj_set_scroll_snap_x(pager, LV_SCROLL_SNAP_CENTER);
        lv_obj_set_flag(pager, LV_OBJ_FLAG_SCROLL_ONE, true);
        lv_obj_set_scrollbar_mode(pager, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_bg_opa(pager, (255 * 0 / 100), 0);
        lv_obj_set_style_border_width(pager, 0, 0);
        lv_obj_set_style_pad_all(pager, 0, 0);
        lv_obj_t * page_left = lv_obj_create(pager);
        lv_obj_set_name(page_left, "page_left");
        lv_obj_set_x(page_left, 0);
        lv_obj_set_y(page_left, 0);
        lv_obj_set_width(page_left, 466);
        lv_obj_set_height(page_left, 466);
        lv_obj_set_flag(page_left, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(page_left, LV_OBJ_FLAG_SNAPPABLE, true);
        lv_obj_set_style_bg_opa(page_left, (255 * 0 / 100), 0);
        lv_obj_set_style_border_width(page_left, 0, 0);
        lv_obj_set_style_pad_all(page_left, 0, 0);
        face_weather_create(page_left);

        lv_obj_t * page_center = lv_obj_create(pager);
        lv_obj_set_name(page_center, "page_center");
        lv_obj_set_x(page_center, 466);
        lv_obj_set_y(page_center, 0);
        lv_obj_set_width(page_center, 466);
        lv_obj_set_height(page_center, 466);
        lv_obj_set_flag(page_center, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(page_center, LV_OBJ_FLAG_SNAPPABLE, true);
        lv_obj_set_style_bg_opa(page_center, (255 * 0 / 100), 0);
        lv_obj_set_style_border_width(page_center, 0, 0);
        lv_obj_set_style_pad_all(page_center, 0, 0);
        face_dial_create(page_center);

        lv_obj_t * page_right = lv_obj_create(pager);
        lv_obj_set_name(page_right, "page_right");
        lv_obj_set_x(page_right, 932);
        lv_obj_set_y(page_right, 0);
        lv_obj_set_width(page_right, 466);
        lv_obj_set_height(page_right, 466);
        lv_obj_set_flag(page_right, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(page_right, LV_OBJ_FLAG_SNAPPABLE, true);
        lv_obj_set_style_bg_opa(page_right, (255 * 0 / 100), 0);
        lv_obj_set_style_border_width(page_right, 0, 0);
        lv_obj_set_style_pad_all(page_right, 0, 0);
        face_health_create(page_right);

        lv_obj_t * dot1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(dot1, "dot1");
        lv_obj_set_width(dot1, 10);
        lv_obj_set_height(dot1, 10);
        lv_obj_set_align(dot1, LV_ALIGN_CENTER);
        lv_obj_set_x(dot1, -24);
        lv_obj_set_y(dot1, 205);
        lv_obj_set_flag(dot1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(dot1, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_style_radius(dot1, 100, 0);
        lv_obj_set_style_bg_color(dot1, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_bg_opa(dot1, (255 * 40 / 100), 0);
        lv_obj_set_style_border_width(dot1, 0, 0);
        lv_obj_bind_style(dot1, &style_dot_active, 0, &subject_page, 0);

        lv_obj_t * dot2 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(dot2, "dot2");
        lv_obj_set_width(dot2, 10);
        lv_obj_set_height(dot2, 10);
        lv_obj_set_align(dot2, LV_ALIGN_CENTER);
        lv_obj_set_x(dot2, 0);
        lv_obj_set_y(dot2, 205);
        lv_obj_set_flag(dot2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(dot2, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_style_radius(dot2, 100, 0);
        lv_obj_set_style_bg_color(dot2, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_bg_opa(dot2, (255 * 40 / 100), 0);
        lv_obj_set_style_border_width(dot2, 0, 0);
        lv_obj_bind_style(dot2, &style_dot_active, 0, &subject_page, 1);

        lv_obj_t * dot3 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(dot3, "dot3");
        lv_obj_set_width(dot3, 10);
        lv_obj_set_height(dot3, 10);
        lv_obj_set_align(dot3, LV_ALIGN_CENTER);
        lv_obj_set_x(dot3, 24);
        lv_obj_set_y(dot3, 205);
        lv_obj_set_flag(dot3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_flag(dot3, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_style_radius(dot3, 100, 0);
        lv_obj_set_style_bg_color(dot3, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_bg_opa(dot3, (255 * 40 / 100), 0);
        lv_obj_set_style_border_width(dot3, 0, 0);
        lv_obj_bind_style(dot3, &style_dot_active, 0, &subject_page, 2);

        the_root = lv_obj_0;
    }
    #endif

    if (the_root) screen_created = true;

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

