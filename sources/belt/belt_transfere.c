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

int wich_next(belt_t *temp, sfVector2i ij)
{
    int next;
    (temp->type == 1) ? (next = ij.y * MAP_SIZE_X + (ij.x + 1)) : (0);
    (temp->type == 2) ? (next = ij.y * MAP_SIZE_X + (ij.x - 1)) : (0);
    (temp->type == 3) ? (next = (ij.y - 1) * MAP_SIZE_X + ij.x) : (0);
    (temp->type == 4) ? (next = (ij.y + 1) * MAP_SIZE_X + ij.x) : (0);
    (temp->type == 5) ? (next = (ij.y - 1) * MAP_SIZE_X + ij.x) : (0);
    (temp->type == 6) ? (next = (ij.y + 1) * MAP_SIZE_X + ij.x) : (0);
    (temp->type == 7) ? (next = ij.y * MAP_SIZE_X + (ij.x + 1)) : (0);
    (temp->type == 8) ? (next = ij.y * MAP_SIZE_X + (ij.x - 1)) : (0);
    (temp->type == 9) ? (next = (ij.y - 1) * MAP_SIZE_X + ij.x) : (0);
    (temp->type == 10) ? (next = (ij.y + 1) * MAP_SIZE_X + ij.x) : (0);
    (temp->type == 11) ? (next = ij.y * MAP_SIZE_X + (ij.x - 1)) : (0);
    (temp->type == 12) ? (next = ij.y * MAP_SIZE_X + (ij.x + 1)) : (0);
    return next;
}

void transfere(belt_t *temp, sfVector2i ij, all_belts_t *belts,
elements_t *elements)
{
    int next = wich_next(temp, ij);

    if (belts->belts[next]) {
        if (belts->belts[next]->in == temp->out && belts->belts[next]->item
        == 0) {
            put_item_on_belt(belts->belts[next], temp->item, elements);
            free_sprite(temp->item_sprite);
            temp->item_sprite = NULL;
            temp->item = 0;
            temp->item_pos = 0;
        }
    }
}
