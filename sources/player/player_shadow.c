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

void set_pixel_on_image(player_t *player, sfVector2i ab, int x, int y)
{
    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 22; ++i) {
            sfImage_setPixel((x == 71) ? (player->idle_shadow) :
            (player->running_shadow), ab.x + (x * i), ab.y + (y * j),
            sfColor_fromRGBA(0, 0, 0, 0));
        }
    }
}

void refresh_idle_mask(sfVector2i ia, int *b, player_t *player, map_t *map)
{
    for (int j = player->pos.y - 90 / 2; j < (player->pos.y - 90 / 2) + 90;
    ++j) {
        if (comp_color(sfImage_getPixel(map->colormap, ia.x, j), sfGreen)) {
            set_pixel_on_image(player, define_vectori(ia.y, *b), 71, 90);
        }
        ++*b;
    }
}

void refresh_running_mask(sfVector2i ia, int *b, player_t *player, map_t *map)
{
    for (int j = player->pos.y - 102 / 2; j < (player->pos.y - 102 / 2) + 102;
    ++j) {
        if (comp_color(sfImage_getPixel(map->colormap, ia.x, j), sfGreen)) {
            set_pixel_on_image(player, define_vectori(ia.y, *b), 68, 102);
        }
        ++*b;
    }
}

void running_mask(player_t *player, map_t *map)
{
    int a = 0;
    int b = 0;

    if (player->move != 0) {
        sfImage_copyImage(player->running_shadow, player->running_clear, 0, 0,
        define_rect(0, 0, 1496, 816), sfFalse);
        for (int i = player->pos.x - 68 / 2; i < (player->pos.x - 68 / 2) +
        68; ++i) {
            refresh_running_mask(define_vectori(i, a), &b, player, map);
            ++a;
            b = 0;
        }
    }
}

void change_player_visib(player_t *player, map_t *map)
{
    int a = 0;
    int b = 0;

    if (player->move == 0 || player->move == 3 || player->move == 12 ||
    player->move == 15) {
        sfImage_copyImage(player->idle_shadow, player->idle_clear, 0, 0,
        define_rect(0, 0, 1562, 720), sfFalse);
        for (int i = player->pos.x - 71 / 2; i < (player->pos.x - 71 / 2) +
        71; ++i) {
            refresh_idle_mask(define_vectori(i, a), &b, player, map);
            ++a;
            b = 0;
        }
    }
    running_mask(player, map);
}
