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

int cond_refresh_item(belt_t *temp, elements_t *elements, sfVector2i ij,
sfVector2f p_pos)
{
    if (!temp)
        return 0;
    if (temp->pos.x > -100 && temp->pos.x < elements->win_size.x + 100) {
        if (temp->pos.y > - 100 && temp->pos.y < elements->win_size.y + 100) {
            (temp->item_sprite) ? (set_item_pos(temp, elements)) : (0);
            (temp->item_sprite) ? (refresh_sprite(temp->item_sprite, elements,
            0)) : (0);
        }
    }
}

void refresh_counter_belt(all_belts_t *belts)
{
    belts->counter += 1;
    if (belts->counter == 16)
        belts->counter = 0;
}

int refresh_one_belt(belt_t *temp, all_belts_t *belts, sfVector2i ij,
elements_t *elements)
{
    if (temp)
        temp->sprite->count = belts->counter;
    else
        return 0;
    if (temp->item != 0) {
        if (temp->item_pos < 32)
            temp->item_pos += 1;
        else
            transfere(temp, ij, belts, elements);
    }
}
