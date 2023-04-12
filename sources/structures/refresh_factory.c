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

void refresh_activ_fact_sprite(structures_t *structures, elements_t *elements,
sfVector2i ij)
{
    if (MY_FACT->processing && MY_FACT->nb_sprite_sheet >= 2) {
        sfSprite_setPosition(MY_FACT->fact_sprite[1]->sprite, define_vectorf
        (MY_FACT->pos.x + MY_FACT->relative_pos_spr[1].x, MY_FACT->pos.y +
        MY_FACT->relative_pos_spr[1].y));
        refresh_sprite(MY_FACT->fact_sprite[1], elements, 0);
    }
}

void refresh_single_fact(structures_t *structures, elements_t *elements,
sfVector2i ij, sfVector2f p_pos)
{
    MY_FACT->pos = define_vectorf((ij.x * (elements->win_size.y *
    BLOC_PERCENTIL / 100) - (p_pos.x - elements->win_size.x / 2)) + ij.x,
    (ij.y *(elements->win_size.y * BLOC_PERCENTIL / 100) - (p_pos.y -
    elements->win_size.y / 2)) + ij.y);
    if (MY_FACT->pos.x > -100 && MY_FACT->pos.x < elements->win_size.x + 100) {
        if (MY_FACT->pos.y > - 100 && MY_FACT->pos.y < elements->win_size.y +
        100) {
            sfSprite_setPosition(MY_FACT->fact_sprite[0]->sprite,
            define_vectorf(MY_FACT->pos.x + MY_FACT->relative_pos_spr[0].x,
            MY_FACT->pos.y + MY_FACT->relative_pos_spr[0].y));
            refresh_sprite(MY_FACT->fact_sprite[0], elements, 0);
            refresh_activ_fact_sprite(structures, elements, ij);
        }
    }
    refresh_out_fact(structures, ij, elements);
    if (MY_FACT->type == 1 || MY_FACT->type == 3) {
        get_item_fact(structures, elements, ij);
    }
}

void refresh_factories(structures_t *structures, elements_t *elements,
sfVector2f p_pos, map_t *map)
{
    for (int i = 0; i < MAP_SIZE_X; ++i) {
        for (int j = 0; j < MAP_SIZE_Y; ++j) {
            (structures->factories->factory[j * MAP_SIZE_X + i] != NULL) ?
            (refresh_single_fact(structures, elements,
            define_vectori(i, j), p_pos)) : (0);
            (structures->factories->factory[j * MAP_SIZE_X + i] != NULL) ?
            (receipts_fact(structures->factories->factory[j * MAP_SIZE_X + i],
            elements, map)) : (0);
        }
    }
}
