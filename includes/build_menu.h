/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef  BUILD_MENU_H_
    #define BUILD_MENU_H_

    #include "../engine/includes/include_engine.h"

    #define NB_CAT 2

typedef struct cat_s {
    button_t *cat_button;
    sfBool is_active;
    int nb_obj;
    button_t **obj_prev;
}cat_t;

typedef struct b_menu_s {
    sfBool is_active;
    cat_t **categories;
    sprite_sheet_t *back;
    button_t *close_button;
    sfBool closing;
    int time_click;
}b_menu_t;

#endif //BUILD_MENU_H_
