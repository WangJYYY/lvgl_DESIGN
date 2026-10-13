/**
 * @file face_weather_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "face_weather_gen.h"
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

lv_obj_t * face_weather_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "face_weather_#");
        lv_obj_set_width(lv_obj_0, 466);
        lv_obj_set_height(lv_obj_0, 466);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_bg_opa(lv_obj_0, (255 * 0 / 100), 0);

        lv_obj_t * city_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(city_label, "city_label");
        lv_label_set_text(city_label, "SHANGHAI");
        lv_obj_set_align(city_label, LV_ALIGN_CENTER);
        lv_obj_set_y(city_label, -150);
        lv_obj_set_style_text_color(city_label, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_text_font(city_label, font_h5, 0);

        lv_obj_t * cond_icon = lv_image_create(lv_obj_0);
        lv_obj_set_name(cond_icon, "cond_icon");
        lv_image_set_src(cond_icon, icon_sun_48);
        lv_obj_set_align(cond_icon, LV_ALIGN_CENTER);
        lv_obj_set_y(cond_icon, -95);
        lv_obj_set_style_image_recolor(cond_icon, COLOR_WARN, 0);
        lv_obj_set_style_image_recolor_opa(cond_icon, (255 * 100 / 100), 0);

        lv_obj_t * temp_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(temp_label, "temp_label");
        lv_obj_set_align(temp_label, LV_ALIGN_CENTER);
        lv_obj_set_y(temp_label, -15);
        lv_label_bind_text(temp_label, &subject_temp, "%d°");
        lv_obj_set_style_text_font(temp_label, font_h1, 0);

        lv_obj_t * cond_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(cond_label, "cond_label");
        lv_label_set_text(cond_label, "SUNNY");
        lv_obj_set_align(cond_label, LV_ALIGN_CENTER);
        lv_obj_set_y(cond_label, 44);
        lv_obj_set_style_text_font(cond_label, font_h4, 0);

        lv_obj_t * hum_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(hum_label, "hum_label");
        lv_obj_set_align(hum_label, LV_ALIGN_CENTER);
        lv_obj_set_y(hum_label, 98);
        lv_label_bind_text(hum_label, &subject_humidity, "HUM %d%%");
        lv_obj_set_style_text_color(hum_label, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_text_font(hum_label, font_h5, 0);

        lv_obj_t * day1_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(day1_label, "day1_label");
        lv_label_set_text(day1_label, "MON  21°");
        lv_obj_set_align(day1_label, LV_ALIGN_CENTER);
        lv_obj_set_y(day1_label, 124);
        lv_obj_set_style_text_font(day1_label, font_h5, 0);

        lv_obj_t * day2_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(day2_label, "day2_label");
        lv_label_set_text(day2_label, "TUE  19°");
        lv_obj_set_align(day2_label, LV_ALIGN_CENTER);
        lv_obj_set_y(day2_label, 154);
        lv_obj_set_style_text_color(day2_label, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_text_font(day2_label, font_h5, 0);

        lv_obj_t * day3_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(day3_label, "day3_label");
        lv_label_set_text(day3_label, "WED  22°");
        lv_obj_set_align(day3_label, LV_ALIGN_CENTER);
        lv_obj_set_y(day3_label, 184);
        lv_obj_set_style_text_color(day3_label, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_text_font(day3_label, font_h5, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

