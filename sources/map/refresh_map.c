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

void refresh_map(sprite_sheet_t *map, elements_t *elements, player_t *player)
{
    sfSprite_setPosition(map->sprite, define_vectorf(-(player->pos.x -
    elements->win_size.x / 2), -(player->pos.y - elements->win_size.y / 2)));
    refresh_sprite(map, elements, 0);
}
