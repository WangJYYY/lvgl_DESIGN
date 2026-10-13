/**
 * @file screen_components_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_components_gen.h"
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

lv_obj_t * screen_components_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static bool screen_created = false;
    if (screen_created) {
        LV_LOG_WARN("`screen_components` is already initialized as a permanent screen. Returning with no change.");
        return screen_components;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        screen_components = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = screen_components;
        lv_obj_set_name_static(lv_obj_0, "screen_components_#");
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
        face_health_create(bezel);

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

