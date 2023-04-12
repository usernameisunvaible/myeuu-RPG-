/*
** EPITECH PROJECT, 2022
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** refresh_assets
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void refresh_all(menu_t m, elements_t *elements)
{
    refresh_sprite(m.bg, elements, 0);
    m.showcustom == 1 ? refresh_sprite(m.defaultskin, elements, 0) : 0;
    m.showcustom == 2 ? refresh_sprite(m.redskin, elements, 0) : 0;
    m.showcustom == 3 ? refresh_sprite(m.blueskin, elements, 0) : 0;
    m.showcustom == 4 ? refresh_sprite(m.lgbtskin, elements, 0) : 0;
    show_button(m.play, elements);
    show_button(m.opt, elements);
    show_button(m.quit, elements);
    show_button(m.right_arrow, elements);
    show_button(m.left_arrow, elements);
    m.optvis >= 1 ? refresh_sprite(m.optgui, elements, 0) : 0;
}

void rf(elements_t *elements, menu_t m)
{
    refresh_all(m, elements);
    refresh_elements(elements);
}
