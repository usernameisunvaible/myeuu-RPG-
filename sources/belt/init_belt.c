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

all_belts_t *init_belts(void)
{
    all_belts_t *tmp = malloc(sizeof(all_belts_t));

    tmp->counter = 0;
    tmp->belts = malloc(sizeof(belt_t *) * MAP_SIZE_X * MAP_SIZE_Y);
    for (int i = 0; i < MAP_SIZE_X; ++i) {
        for (int j = 0; j < MAP_SIZE_Y; ++j) {
            tmp->belts[j * MAP_SIZE_Y + i] = NULL;
        }
    }
    tmp->timer_tot = 0;
    tmp->timer = 0;
}

void define_type_two(int type, belt_t *belt)
{
    (type == 7) ? (belt->in = T) : (0);
    (type == 7) ? (belt->out = L) : (0);
    (type == 8) ? (belt->in = T) : (0);
    (type == 8) ? (belt->out = R) : (0);
    (type == 9) ? (belt->in = L) : (0);
    (type == 9) ? (belt->out = B) : (0);
    (type == 10) ? (belt->in = L) : (0);
    (type == 10) ? (belt->out = T) : (0);
    (type == 11) ? (belt->in = B) : (0);
    (type == 11) ? (belt->out = R) : (0);
    (type == 12) ? (belt->in = B) : (0);
    (type == 12) ? (belt->out = L) : (0);
}

void define_type(int type, belt_t *belt)
{
    (type == 1) ? (belt->in = L) : (0);
    (type == 1) ? (belt->out = L) : (0);
    (type == 2) ? (belt->in = R) : (0);
    (type == 2) ? (belt->out = R) : (0);
    (type == 3) ? (belt->in = B) : (0);
    (type == 3) ? (belt->out = B) : (0);
    (type == 4) ? (belt->in = T) : (0);
    (type == 4) ? (belt->out = T) : (0);
    (type == 5) ? (belt->in = R) : (0);
    (type == 5) ? (belt->out = B) : (0);
    (type == 6) ? (belt->in = R) : (0);
    (type == 6) ? (belt->out = T) : (0);
    define_type_two(type, belt);
}

void add_belt(int type, elements_t *elements, belt_t **belt_list,
sfVector2i pos)
{
    belt_t *belt = malloc(sizeof(belt_t));
    const float belt_size = 32;
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);

    belt->type = type;
    belt->sprite = sprite_factory(elements, define_sprite_param(
    "assets/belt.png", 15, 16, define_rect(0, (type - 1) *
    belt_size, belt_size, belt_size)));
    sfSprite_setScale(belt->sprite->sprite, define_vectorf((bloc_size *
    belt_size / 100) / 10, (bloc_size * belt_size / 100) / 10));
    belt->item_pos = 0;
    belt->item = 0;
    belt->item_sprite = NULL;
    define_type(type, belt);
    belt_list[pos.y * MAP_SIZE_X + pos.x] = belt;
}

void del_belt(belt_t *belt)
{
    if (belt->item_sprite)
        free_sprite(belt->item_sprite);
    free_sprite(belt->sprite);
    free(belt);
}
