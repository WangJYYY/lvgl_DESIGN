/**
 * @file face_dial_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "face_dial_gen.h"
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

lv_obj_t * face_dial_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_sec_track;
    static lv_style_t style_sec_ind;
    static lv_style_t style_knob_hidden;
    static lv_style_t style_scale_minor;
    static lv_style_t style_scale_major;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_sec_track);
        lv_style_init(&style_sec_ind);
        lv_style_init(&style_knob_hidden);
        lv_style_init(&style_scale_minor);
        lv_style_init(&style_scale_major);

        lv_style_set_arc_width(&style_sec_track, 6);
        lv_style_set_arc_color(&style_sec_track, COLOR_WATCH_PANEL2);
        lv_style_set_arc_rounded(&style_sec_track, true);
        lv_style_set_arc_width(&style_sec_ind, 6);
        lv_style_set_arc_color(&style_sec_ind, COLOR_DATA);
        lv_style_set_arc_rounded(&style_sec_ind, true);
        lv_style_set_bg_opa(&style_knob_hidden, (255 * 0 / 100));
        lv_style_set_line_color(&style_scale_minor, COLOR_WATCH_PANEL2);
        lv_style_set_length(&style_scale_minor, 10);
        lv_style_set_line_color(&style_scale_major, COLOR_WATCH_TEXT2);
        lv_style_set_line_width(&style_scale_major, 3);
        lv_style_set_length(&style_scale_major, 18);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "face_dial_#");
        lv_obj_set_width(lv_obj_0, 466);
        lv_obj_set_height(lv_obj_0, 466);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_bg_opa(lv_obj_0, (255 * 0 / 100), 0);

        lv_obj_t * sec_ring = lv_arc_create(lv_obj_0);
        lv_obj_set_name(sec_ring, "sec_ring");
        lv_obj_set_width(sec_ring, 440);
        lv_obj_set_height(sec_ring, 440);
        lv_obj_set_align(sec_ring, LV_ALIGN_CENTER);
        lv_obj_set_flag(sec_ring, LV_OBJ_FLAG_CLICKABLE, false);
        lv_arc_set_min_value(sec_ring, 0);
        lv_arc_set_max_value(sec_ring, 59);
        lv_arc_set_bg_start_angle(sec_ring, 270);
        lv_arc_set_bg_end_angle(sec_ring, 269);
        lv_arc_bind_value(sec_ring, &subject_seconds);
        lv_obj_add_style(sec_ring, &style_sec_track, LV_PART_MAIN);
        lv_obj_add_style(sec_ring, &style_sec_ind, LV_PART_INDICATOR);
        lv_obj_add_style(sec_ring, &style_knob_hidden, LV_PART_KNOB);

        lv_obj_t * ticks = lv_scale_create(lv_obj_0);
        lv_obj_set_name(ticks, "ticks");
        lv_obj_set_width(ticks, 440);
        lv_obj_set_height(ticks, 440);
        lv_obj_set_align(ticks, LV_ALIGN_CENTER);
        lv_scale_set_mode(ticks, LV_SCALE_MODE_ROUND_INNER);
        lv_scale_set_min_value(ticks, 0);
        lv_scale_set_max_value(ticks, 60);
        lv_scale_set_total_tick_count(ticks, 61);
        lv_scale_set_major_tick_every(ticks, 5);
        lv_scale_set_angle_range(ticks, 360);
        lv_scale_set_rotation(ticks, 270);
        lv_scale_set_label_show(ticks, false);
        lv_obj_add_style(ticks, &style_scale_minor, LV_PART_ITEMS);
        lv_obj_add_style(ticks, &style_scale_major, LV_PART_INDICATOR);

        lv_obj_t * time_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(time_label, "time_label");
        lv_obj_set_align(time_label, LV_ALIGN_CENTER);
        lv_obj_set_y(time_label, -30);
        lv_label_bind_text(time_label, &subject_time, NULL);
        lv_obj_set_style_text_font(time_label, font_time, 0);

        lv_obj_t * date_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(date_label, "date_label");
        lv_obj_set_align(date_label, LV_ALIGN_CENTER);
        lv_obj_set_y(date_label, 34);
        lv_label_bind_text(date_label, &subject_date, NULL);
        lv_obj_set_style_text_color(date_label, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_text_font(date_label, font_h5, 0);

        lv_obj_t * battery_icon = lv_image_create(lv_obj_0);
        lv_obj_set_name(battery_icon, "battery_icon");
        lv_image_set_src(battery_icon, icon_battery);
        lv_obj_set_align(battery_icon, LV_ALIGN_CENTER);
        lv_obj_set_x(battery_icon, -26);
        lv_obj_set_y(battery_icon, 150);

        lv_obj_t * battery_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(battery_label, "battery_label");
        lv_obj_set_align(battery_label, LV_ALIGN_CENTER);
        lv_obj_set_x(battery_label, 24);
        lv_obj_set_y(battery_label, 150);
        lv_label_bind_text(battery_label, &subject_battery, "%d%%");
        lv_obj_set_style_text_color(battery_label, COLOR_WATCH_TEXT2, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

