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

int cond_refresh_belt(belt_t *temp, elements_t *elements, sfVector2i ij,
sfVector2f p_pos)
{
    if (temp)
        temp->pos = define_vectorf((ij.x *
        (elements->win_size.y *BLOC_PERCENTIL / 100) -
        (p_pos.x - elements->win_size.x / 2)) + ij.x,
        (ij.y *(elements->win_size.y * BLOC_PERCENTIL / 100) -
        (p_pos.y -elements->win_size.y / 2)) + ij.y);
    else
        return 0;
    if (temp->pos.x > -100 && temp->pos.x < elements->win_size.x + 100) {
        if (temp->pos.y > - 100 && temp->pos.y < elements->win_size.y + 100) {
            sfSprite_setPosition(temp->sprite->sprite, define_vectorf
            (temp->pos.x, temp->pos.y));
            refresh_sprite(temp->sprite, elements, 1);
        }
    }
}

void move_belt(all_belts_t *belts, elements_t *elements)
{
    for (int i = 0; i < MAP_SIZE_X; ++i) {
        for (int j = 0; j < MAP_SIZE_Y; ++j) {
            refresh_one_belt(belts->belts[j * MAP_SIZE_X + i], belts,
            define_vectori(i, j), elements);
        }
    }
}

void put_on_screen(all_belts_t *belts, elements_t *elements,
sfVector2f player_pos)
{
    for (int i = 0; i < MAP_SIZE_X; ++i) {
        for (int j = 0; j < MAP_SIZE_Y; ++j) {
            cond_refresh_belt(belts->belts[j * MAP_SIZE_X + i],
            elements, define_vectori(i, j), player_pos);
        }
    }
    for (int i = 0; i < MAP_SIZE_X; ++i) {
        for (int j = 0; j < MAP_SIZE_Y; ++j) {
            cond_refresh_item(belts->belts[j * MAP_SIZE_X + i],
            elements, define_vectori(i, j), player_pos);
        }
    }
}

void refresh_belts(all_belts_t *belts, elements_t *elements,
sfVector2f player_pos)
{
    int refresh_time = 30;

    belts->timer_tot += elements->chrono->ms - belts->timer;
    while (belts->timer_tot >= (int)1000/refresh_time) {
        refresh_counter_belt(belts);
        move_belt(belts, elements);
        belts->timer_tot -= (int)1000/refresh_time;
    }
    belts->timer = elements->chrono->ms;
    put_on_screen(belts, elements, player_pos);
}
