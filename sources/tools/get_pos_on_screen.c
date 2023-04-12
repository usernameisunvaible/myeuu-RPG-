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

sfVector2f get_pos_on_screen(sfVector2i grid_pos, elements_t *elements,
player_t *player)
{
    sfVector2f pos = define_vectorf((grid_pos.x * (elements->win_size.y *
    BLOC_PERCENTIL / 100) - (player->pos.x - elements->win_size.x / 2)) +
    grid_pos.x, (grid_pos.y * (elements->win_size.y * BLOC_PERCENTIL / 100) -
    (player->pos.y - elements->win_size.y / 2)) + grid_pos.y);
    return pos;
}
