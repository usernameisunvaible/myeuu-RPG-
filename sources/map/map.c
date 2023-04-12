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

map_t *init_map(elements_t *elements)
{
    map_t *temp = malloc(sizeof(map_t));
    temp->map = sprite_factory(elements, define_sprite_param("assets/map.png",
    0, 0, define_rect(0, 0, 7488, 8000)));
    sfSprite_setScale(temp->map->sprite, define_vectorf(1.8, 1.8));
    temp->colormap = sfImage_createFromFile("assets/colormap.png");
    return temp;
}

sfBool comp_color(sfColor a, sfColor b)
{
    if (a.r != b.r)
        return sfFalse;
    if (a.g != b.g)
        return sfFalse;
    if (a.b != b.b)
        return sfFalse;
    return sfTrue;
}

int detect_bad_pix(int i, int j, sfImage *colormap)
{
    sfColor color = sfImage_getPixel(colormap, i, j);
    if (comp_color(color, sfColor_fromRGB(0, 38, 255)) == sfTrue)
        return 1;
    if (comp_color(color, sfColor_fromRGB(255, 238, 0)) == sfTrue)
        return 1;
    return 0;
}

sfBool detect_col(sfImage *colormap, player_t *player, sfVector2f next_pos)
{
    int temp = 0;
    for (int i = next_pos.x - player->hit_box.left; i < next_pos.x +
    player->hit_box.width; ++i) {
        for (int j = next_pos.y - player->hit_box.top; j < next_pos.y +
        player->hit_box.height; ++j)
            temp += detect_bad_pix(i, j, colormap);
    }
    if (temp > 0)
        return sfFalse;
    else
        return sfTrue;
}

void color_colosion(sfImage *colormap, player_t *player, sfVector2f next_pos)
{
    if (detect_col(colormap, player, next_pos) == sfFalse)
        player->move = 0;
}
