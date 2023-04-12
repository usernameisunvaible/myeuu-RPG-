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

void put_item_on_belt(belt_t *temp, int item, elements_t *elements)
{
    const float bloc_size = (elements->win_size.y * (BLOC_PERCENTIL) / 100);

    temp->item_sprite = sprite_factory(elements, define_sprite_param(
    "assets/icon.png", 0, 0, define_rect(0, 64 * (item - 1), 64, 64)));
    sfSprite_setScale(temp->item_sprite->sprite, define_vectorf((
    bloc_size / 2 * 100 / 64) / 100, (bloc_size / 2 * 100 / 64) / 100));
    temp->item_size = define_vectorf(64 * ((bloc_size / 2 * 100 / 64) /
    100), 64 * ((bloc_size / 2 * 100 / 64) / 100));
    temp->item = item;
    temp->item_pos = 0;
}
