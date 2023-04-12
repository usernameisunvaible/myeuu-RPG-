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

void init_belt_cat_textures(cat_t *temp, elements_t *elements, sfVector2f pos,
const sfVector2f start_pos)
{
    temp->obj_prev[6] = init_button(elements, define_button_params("assets/\
belt_button/bb_tr.png", define_rect((start_pos.x + 24) + 72 * 6, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[7] = init_button(elements, define_button_params("assets/\
belt_button/bb_tl.png", define_rect((start_pos.x + 24) + 72 * 7, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[8] = init_button(elements, define_button_params("assets/\
belt_button/bb_lt.png", define_rect((start_pos.x + 24) + 72 * 8, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[9] = init_button(elements, define_button_params("assets/\
belt_button/bb_lb.png", define_rect((start_pos.x + 24) + 72 * 9, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[10] = init_button(elements, define_button_params("assets/\
belt_button/bb_bl.png", define_rect((start_pos.x + 24) + 72 * 10, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[11] = init_button(elements, define_button_params("assets/\
belt_button/bb_br.png", define_rect((start_pos.x + 24) + 72 * 11, start_pos.y
+ 24, 48, 48), 16, 15));
}

void init_belt_cat_textures_two(cat_t *temp, elements_t *elements,
sfVector2f pos, const sfVector2f start_pos)
{
    temp->obj_prev[0] = init_button(elements, define_button_params("assets/\
belt_button/bb_lr.png", define_rect((start_pos.x + 24) + 72 * 0, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[1] = init_button(elements, define_button_params("assets/\
belt_button/bb_rl.png", define_rect((start_pos.x + 24) + 72 * 1, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[2] = init_button(elements, define_button_params("assets/\
belt_button/bb_bt.png", define_rect((start_pos.x + 24) + 72 * 2, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[3] = init_button(elements, define_button_params("assets/\
belt_button/bb_tb.png", define_rect((start_pos.x + 24) + 72 * 3, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[4] = init_button(elements, define_button_params("assets/\
belt_button/bb_rt.png", define_rect((start_pos.x + 24) + 72 * 4, start_pos.y
+ 24, 48, 48), 16, 15));
    temp->obj_prev[5] = init_button(elements, define_button_params("assets/\
belt_button/bb_rb.png", define_rect((start_pos.x + 24) + 72 * 5, start_pos.y
+ 24, 48, 48), 16, 15));
}

void init_belt_cat(cat_t *temp, elements_t *elements, sfVector2f pos)
{
    const sfVector2f start_pos = define_vectorf(elements->win_size.x / 8 + 30,
elements->win_size.y / 8 + 24 + 56);

    temp->cat_button = init_button(elements, define_button_params("assets/\
belt_button/prev_belt.png", define_rect(pos.x, pos.y, 56, 56), 16, 15));
    show_b(temp->cat_button);
    temp->nb_obj = 12;
    temp->obj_prev = malloc(sizeof(button_t *) * temp->nb_obj);
    init_belt_cat_textures(temp, elements, pos, start_pos);
    init_belt_cat_textures_two(temp, elements, pos, start_pos);
    for (int i = 0; i < temp->nb_obj ; ++i)
        show_b(temp->obj_prev[i]);
}

void button_belt_action(b_menu_t *b_menu, player_t *player,
elements_t *elements)
{
    for (int i = 0; i < b_menu->categories[0]->nb_obj; ++i) {
        if (b_menu->categories[0]->obj_prev[i]->infos & CLICK_F) {
            b_menu->closing = sfTrue;
            b_menu->time_click = elements->chrono->ms;
            unclick_b(b_menu->categories[0]->obj_prev[i]);
            player->editor->obj = i;
        }
    }
}
