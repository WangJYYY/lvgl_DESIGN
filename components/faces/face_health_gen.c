/**
 * @file face_health_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "face_health_gen.h"
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

lv_obj_t * face_health_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_goal_track;
    static lv_style_t style_goal_ind;
    static lv_style_t style_knob_hidden;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_goal_track);
        lv_style_init(&style_goal_ind);
        lv_style_init(&style_knob_hidden);

        lv_style_set_arc_width(&style_goal_track, 14);
        lv_style_set_arc_color(&style_goal_track, COLOR_WATCH_PANEL2);
        lv_style_set_arc_rounded(&style_goal_track, true);
        lv_style_set_arc_width(&style_goal_ind, 14);
        lv_style_set_arc_color(&style_goal_ind, COLOR_OK);
        lv_style_set_arc_rounded(&style_goal_ind, true);
        lv_style_set_bg_opa(&style_knob_hidden, (255 * 0 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "face_health_#");
        lv_obj_set_width(lv_obj_0, 466);
        lv_obj_set_height(lv_obj_0, 466);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_bg_opa(lv_obj_0, (255 * 0 / 100), 0);

        lv_obj_t * goal_ring = lv_arc_create(lv_obj_0);
        lv_obj_set_name(goal_ring, "goal_ring");
        lv_obj_set_width(goal_ring, 320);
        lv_obj_set_height(goal_ring, 320);
        lv_obj_set_align(goal_ring, LV_ALIGN_CENTER);
        lv_obj_set_y(goal_ring, -50);
        lv_obj_set_flag(goal_ring, LV_OBJ_FLAG_CLICKABLE, false);
        lv_arc_set_min_value(goal_ring, 0);
        lv_arc_set_max_value(goal_ring, 10000);
        lv_arc_set_bg_start_angle(goal_ring, 270);
        lv_arc_set_bg_end_angle(goal_ring, 269);
        lv_arc_bind_value(goal_ring, &subject_steps);
        lv_obj_add_style(goal_ring, &style_goal_track, LV_PART_MAIN);
        lv_obj_add_style(goal_ring, &style_goal_ind, LV_PART_INDICATOR);
        lv_obj_add_style(goal_ring, &style_knob_hidden, LV_PART_KNOB);

        lv_obj_t * steps_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(steps_label, "steps_label");
        lv_obj_set_align(steps_label, LV_ALIGN_CENTER);
        lv_obj_set_y(steps_label, -66);
        lv_label_bind_text(steps_label, &subject_steps, NULL);
        lv_obj_set_style_text_font(steps_label, font_h1, 0);

        lv_obj_t * steps_caption = lv_label_create(lv_obj_0);
        lv_obj_set_name(steps_caption, "steps_caption");
        lv_label_set_text(steps_caption, "STEPS TODAY");
        lv_obj_set_align(steps_caption, LV_ALIGN_CENTER);
        lv_obj_set_y(steps_caption, -16);
        lv_obj_set_style_text_color(steps_caption, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_text_font(steps_caption, font_h5, 0);

        lv_obj_t * hr_icon = lv_image_create(lv_obj_0);
        lv_obj_set_name(hr_icon, "hr_icon");
        lv_image_set_src(hr_icon, icon_heart_48);
        lv_obj_set_align(hr_icon, LV_ALIGN_CENTER);
        lv_obj_set_x(hr_icon, -65);
        lv_obj_set_y(hr_icon, 138);
        lv_obj_set_style_image_recolor(hr_icon, COLOR_DANGER, 0);
        lv_obj_set_style_image_recolor_opa(hr_icon, (255 * 100 / 100), 0);

        lv_obj_t * hr_label = lv_label_create(lv_obj_0);
        lv_obj_set_name(hr_label, "hr_label");
        lv_obj_set_align(hr_label, LV_ALIGN_CENTER);
        lv_obj_set_x(hr_label, -4);
        lv_obj_set_y(hr_label, 142);
        lv_label_bind_text(hr_label, &subject_hr, NULL);
        lv_obj_set_style_text_font(hr_label, font_h2, 0);
        lv_obj_set_style_text_color(hr_label, COLOR_DANGER, 0);

        lv_obj_t * hr_caption = lv_label_create(lv_obj_0);
        lv_obj_set_name(hr_caption, "hr_caption");
        lv_label_set_text(hr_caption, "BPM");
        lv_obj_set_align(hr_caption, LV_ALIGN_CENTER);
        lv_obj_set_x(hr_caption, 57);
        lv_obj_set_y(hr_caption, 143);
        lv_obj_set_style_text_color(hr_caption, COLOR_WATCH_TEXT2, 0);
        lv_obj_set_style_text_font(hr_caption, font_h5, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

