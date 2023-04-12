/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>
#include <stdio.h>

b_menu_t *init_build_menu(elements_t *elements)
{
    b_menu_t *temp = malloc(sizeof(b_menu_t));
    const float bloc_size = (elements->win_size.y * (75) / 100);
    const float start_posx_menu = (elements->win_size.x / 8);
    temp->is_active = sfFalse;
    temp->back = sprite_factory(elements, define_sprite_param("assets/belts\
_menu.png", 0, 0, define_rect(0, 0, 1920, 1080)));
    temp->close_button = init_button(elements, define_button_params("assets/c\
arre_bleu.png", define_rect(start_posx_menu * 7 - 54, elements->win_size.y /
    8 - 2, 24, 24), 0, 0));
    show_b(temp->close_button);
    temp->categories = malloc(sizeof(cat_t *) * NB_CAT);
    temp->closing = sfFalse;
    temp->time_click = 0;
    temp->categories[0] = init_categorie(elements, define_vectorf((
    start_posx_menu + 24 + 40) * 1, elements->win_size.y / 8 + 24),
    &init_belt_cat);
    temp->categories[1] = init_categorie(elements, define_vectorf((
    start_posx_menu + 147) * 1, elements->win_size.y / 8 + 24),
    &init_fact_cat);
    return temp;
}

void closing(b_menu_t *b_menu, elements_t *elements, player_t *player)
{
    if (elements->chrono->ms - b_menu->time_click >= 130) {
        b_menu->is_active = sfFalse;
        elements->left = sfFalse;
        b_menu->time_click = 0;
        b_menu->closing = sfFalse;
        player->editor->isactive = sfTrue;
    }
}

void open_cat(cat_t *cat, b_menu_t *b_menu)
{
    if (cat->cat_button->infos & CLICK_F) {
        for (int i = 0; i < NB_CAT; ++i)
            b_menu->categories[i]->is_active = sfFalse;
        unclick_b(cat->cat_button);
        cat->is_active = sfTrue;
    }
}

void refresh_build_menu(elements_t *elements, b_menu_t *b_menu,
player_t *player, sprite_t *sprite)
{
    if (b_menu->is_active && !sprite->on_inventory &&
    !elements->is_on_p_menu) {
        sfRenderWindow_setMouseCursorVisible(elements->window, sfTrue);
        refresh_sprite(b_menu->back, elements, 0);
        show_button(b_menu->close_button, elements);
        for (int i = 0; i < NB_CAT; ++i) {
            open_cat(b_menu->categories[i], b_menu);
            refresh_one_cat(elements, b_menu->categories[i], player, b_menu);
        }
        if (b_menu->close_button->infos & CLICK_F) {
            b_menu->is_active = sfFalse;
            unclick_b(b_menu->close_button);
        }
        if (b_menu->closing)
            closing(b_menu, elements, player);
    } else if (!sprite->on_inventory && !elements->is_on_p_menu) {
        sfRenderWindow_setMouseCursorVisible(elements->window, sfFalse);
    }
}
