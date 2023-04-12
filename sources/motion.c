/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../engine/includes/include_engine.h"
#include "../includes/include_all.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

void apply_motion(elements_t *elements, aliens_t *alien, player_t *player,
map_t *map)
{
    alien->timer_tot_ind += elements->chrono->ms - alien->timer_ind;
    while (alien->timer_tot_ind >= 20) {
        sfSprite_setPosition(map->map->sprite, define_vectorf(-(player->pos.x -
elements->win_size.x / 2), -(player->pos.y - elements->win_size.y / 2)));
        move_player(elements, player);
        alien->pos_on_map = get_pos_on_screen(alien->pos_on_grid,
        elements, player);
        alien->rel_pos.x += alien->current_move.x;
        alien->rel_pos.y += alien->current_move.y;
        alien->pos_on_map.x += alien->rel_pos.x;
        alien->pos_on_map.y += alien->rel_pos.y;
        alien->timer_tot_ind -= 20;
    }
    alien->timer_ind = elements->chrono->ms;
}
