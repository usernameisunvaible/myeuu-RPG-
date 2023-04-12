/*
** EPITECH PROJECT, 2022
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** init_menu_assets
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void hard_place(menu_t m, elements_t *elements)
{
    sfSprite_setPosition(m.defaultskin->sprite, define_vectorf(710, 560));
    sfSprite_setPosition(m.redskin->sprite, define_vectorf(710, 560));
    sfSprite_setPosition(m.blueskin->sprite, define_vectorf(710, 560));
    sfSprite_setPosition(m.lgbtskin->sprite, define_vectorf(710, 560));
    sfSprite_setPosition(m.optgui->sprite, (sfVector2f) {450, 150});
}

menu_t init_skin_sprites(menu_t m, elements_t *elements)
{
    m.defaultskin = sprite_factory(elements,
    define_sprite_param("assets/defaultskin.png", 0, 0,
    define_rect(0, 0, 500, 832)));
    m.redskin = sprite_factory(elements,
    define_sprite_param("assets/redskin.png", 0, 0,
    define_rect(0, 0, 500, 832)));
    m.blueskin = sprite_factory(elements,
    define_sprite_param("assets/blueskin.png", 0, 0,
    define_rect(0, 0, 500, 832)));
    m.lgbtskin = sprite_factory(elements,
    define_sprite_param("assets/lgbtskin.png", 0, 0,
    define_rect(0, 0, 500, 832)));
    return (m);
}

menu_t init_skin_selector(menu_t m, elements_t *elements)
{
    m.right_arrow = init_button(elements, define_button_params(
    "assets/rightarrow.png",
    define_rect(1150, 750, 38, 73), 0, 0));
    m.left_arrow = init_button(elements, define_button_params(
    "assets/leftarrow.png",
    define_rect(750, 750, 38, 73), 0, 0));
    show_b(m.right_arrow);
    show_b(m.left_arrow);
    return (m);
}

menu_t init_menu_elems(menu_t m, elements_t *elements)
{
    m = init_skin_sprites(m, elements);
    m = init_skin_selector(m, elements);
    m.bg = sprite_factory(elements,
    define_sprite_param("assets/bgmenu.png", 0, 0,
    define_rect(0, 0, 1920, 1080)));
    m.optgui = sprite_factory(elements,
    define_sprite_param("assets/optgui.png", 0, 0,
    define_rect(0, 0, 1106, 832)));
    m.play = init_button(elements, define_button_params("assets/play.png",
    define_rect(100, 600, 480, 105), 1, 5));
    m.opt = init_button(elements, define_button_params("assets/option.png",
    define_rect(100, 720, 480, 105), 1, 5));
    m.quit = init_button(elements, define_button_params("assets/quit.png",
    define_rect(100, 840, 480, 105), 1, 5));
    show_b(m.play);
    show_b(m.opt);
    show_b(m.quit);
    m.optvis = 0;
    m.showcustom = 1;
    hard_place(m, elements);
    return (m);
}
