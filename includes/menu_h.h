/*
** EPITECH PROJECT, 2022
** main_menu
** File description:
** menu_h
*/

#ifndef MENU_H_H_
#define MENU_H_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#include "../engine/includes/include_engine.h"

typedef struct menu {
    sprite_sheet_t *bg;
    sprite_sheet_t *defaultskin;
    sprite_sheet_t *lgbtskin;
    sprite_sheet_t *blueskin;
    sprite_sheet_t *redskin;
    button_params_t playp;
    button_t *play;
    button_t *left_arrow;
    button_t *right_arrow;
    button_t *opt;
    button_t *quit;
    sprite_sheet_t *optgui;
    int optvis;
    int showcustom;
} menu_t;

void refresh_all(menu_t m, elements_t *elements);
void rf(elements_t *elements, menu_t m);
menu_t skin_buttons(elements_t *elements, menu_t m);
menu_t button_handler(elements_t *elements, menu_t m, all_t *all);
menu_t menu(elements_t *elements, menu_t m, all_t *all);
void hard_place(menu_t m, elements_t *elements);
menu_t init_skin_sprites(menu_t m, elements_t *elements);
menu_t init_skin_selector(menu_t m, elements_t *elements);
menu_t init_menu_elems(menu_t m, elements_t *elements);

#endif /* !MENU_H_H_ */
