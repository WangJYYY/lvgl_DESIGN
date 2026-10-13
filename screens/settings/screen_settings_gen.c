/**
 * @file screen_settings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_settings_gen.h"
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

lv_obj_t * screen_settings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`screen_settings` is already initialized as a permanent screen. Returning with no change.");
        return screen_settings;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        screen_settings = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = screen_settings;
        lv_obj_set_name_static(lv_obj_0, "screen_settings_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x000000), 0);
        lv_obj_set_style_radius(lv_obj_0, 233, 0);
        lv_obj_set_style_clip_corner(lv_obj_0, true, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_watch, 0);
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
        lv_obj_t * settings_page = lv_obj_create(bezel);
        lv_obj_set_name(settings_page, "settings_page");
        lv_obj_set_width(settings_page, 466);
        lv_obj_set_height(settings_page, 466);
        lv_obj_set_flag(settings_page, LV_OBJ_FLAG_SCROLLABLE, true);
        lv_obj_set_scrollbar_mode(settings_page, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_bg_opa(settings_page, (255 * 0 / 100), 0);
        lv_obj_set_style_border_width(settings_page, 0, 0);
        lv_obj_set_style_pad_top(settings_page, WATCH_SIDE_PAD, 0);
        lv_obj_set_style_pad_bottom(settings_page, SPACE_LG, 0);
        lv_obj_set_style_pad_left(settings_page, WATCH_SIDE_PAD, 0);
        lv_obj_set_style_pad_right(settings_page, WATCH_SIDE_PAD, 0);
        lv_obj_t * column_0 = column_create(settings_page, 0, SPACE_LG, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_0, lv_pct(100));
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        h3_create(column_0, "Settings");

        lv_obj_t * sliderbox_0 = sliderbox_create(column_0, "Brightness", &subject_brightness, "%d%%");
        lv_obj_set_width(sliderbox_0, 326);
        lv_obj_set_height(sliderbox_0, 74);

        lv_obj_t * sliderbox_1 = sliderbox_create(column_0, "Screen timeout", &subject_timeout, "%d ms");
        lv_obj_set_width(sliderbox_1, 326);
        lv_obj_set_height(sliderbox_1, 71);

        lv_obj_t * panel_0 = panel_create(column_0, SPACE_LG, SPACE_SM, LV_FLEX_FLOW_COLUMN, 0);
        lv_obj_set_width(panel_0, 326);
        lv_obj_set_height(panel_0, 95);
        h5_create(panel_0, "About", "");

        lv_obj_t * row_0 = row_create(panel_0, 0, SPACE_SM, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_t * lv_image_0 = lv_image_create(row_0);
        lv_image_set_src(lv_image_0, icon_battery);

        lv_obj_t * lv_label_0 = lv_label_create(row_0);
        lv_label_bind_text(lv_label_0, &subject_battery, "Battery %d%%");

        lv_obj_t * lv_label_1 = lv_label_create(panel_0);
        lv_label_set_text(lv_label_1, "Firmware v1.0 (PC sim)");
        lv_obj_set_style_text_color(lv_label_1, COLOR_WATCH_TEXT2, 0);

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

