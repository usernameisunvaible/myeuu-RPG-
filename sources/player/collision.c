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

void move_next(sfVector2f *next_pos, int x, int y)
{
    next_pos->x += x;
    next_pos->y += y;
}

sfVector2f get_next_pos(player_t *player)
{
    sfVector2f next_pos = player->pos;
    ((G_U) && !(G_D) && !(G_L) && !(G_R)) ? (next_pos.y -= P_SP) : (0);
    ((G_U) && !(G_D) && (G_L) && (G_R)) ? (next_pos.y -= P_SP) : (0);
    ((G_U) && !(G_D) && !(G_L) && (G_R)) ? (move_next(&next_pos, P_SP_DI,
    -P_SP_DI)) : (0);
    (!(G_U) && !(G_D) && !(G_L) && (G_R)) ? (next_pos.x += P_SP) : (0);
    ((G_U) && (G_D) && !(G_L) && (G_R)) ? (next_pos.x += P_SP) : (0);
    (!(G_U) && (G_D) && !(G_L) && (G_R)) ? (move_next(&next_pos, P_SP_DI,
    P_SP_DI)): (0);
    (!(G_U) && (G_D) && !(G_L) && !(G_R)) ? (next_pos.y += P_SP): (0);
    (!(G_U) && (G_D) && (G_L) && (G_R)) ? (next_pos.y += P_SP) : (0);
    (!(G_U) && (G_D) && (G_L) && !(G_R)) ? (move_next(&next_pos, -P_SP_DI,
    P_SP_DI)) : (0);
    (!(G_U) && !(G_D) && (G_L) && !(G_R)) ? (next_pos.x -= P_SP) : (0);
    ((G_U) && (G_D) && (G_L) && !(G_R)) ? (next_pos.x -= P_SP) : (0);
    ((G_U) && !(G_D) && (G_L) && !(G_R)) ? (move_next(&next_pos, -P_SP_DI,
    -P_SP_DI)) : (0);
    return next_pos;
}

void col_player(player_t *player, structures_t *structures,
elements_t *elements, map_t *map)
{
    int temp = 0;
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);
    sfVector2f next_pos = get_next_pos(player);

    color_colosion(map->colormap, player, next_pos);
    color_colosion(structures->factories->colimap, player, next_pos);
}
