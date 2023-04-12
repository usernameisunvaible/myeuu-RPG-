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

void init_fact_cat(cat_t *temp, elements_t *elements, sfVector2f pos)
{
    const sfVector2f start_pos = define_vectorf(elements->win_size.x / 8 + 30,
    elements->win_size.y / 8 + 24 + 56);

    temp->cat_button = init_button(elements, define_button_params
    ("assets/struct_cat_button.png", define_rect(pos.x, pos.y, 56, 56), 1, 1));
    show_b(temp->cat_button);
    temp->nb_obj = 3;
    temp->obj_prev = malloc(sizeof(button_t *) * temp->nb_obj);
    temp->obj_prev[0] = init_button(elements, define_button_params
    ("assets/stone_furnace_button.png", define_rect
    ((start_pos.x + 24) + 72 * 0, start_pos.y+ 24, 48, 48), 1, 1));
    temp->obj_prev[1] = init_button(elements, define_button_params
    ("assets/drill_E_button.png", define_rect
    ((start_pos.x + 24) + 72 * 1, start_pos.y+ 24, 48, 48), 1, 1));
    temp->obj_prev[2] = init_button(elements, define_button_params
    ("assets/chest_button.png", define_rect
    ((start_pos.x + 24) + 72 * 2, start_pos.y+ 24, 48, 48), 1, 1));
    for (int i = 0; i < temp->nb_obj ; ++i)
        show_b(temp->obj_prev[i]);
}

void button_fact_action(b_menu_t *b_menu, player_t *player,
elements_t *elements)
{
    for (int i = 0; i < b_menu->categories[1]->nb_obj; ++i) {
        if (b_menu->categories[1]->obj_prev[i]->infos & CLICK_F) {
            b_menu->closing = sfTrue;
            b_menu->time_click = elements->chrono->ms;
            unclick_b(b_menu->categories[1]->obj_prev[i]);
            player->editor->obj = i + 12;
        }
    }
}
