/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

void init_ennemies_two(elements_t *elements, int type, sfVector2i pos_on_grid,
aliens_t *temp)
{
    temp->move_sprite = malloc(sizeof(sprite_sheet_t *) * 5);
    temp->move_sprite[0] = sprite_factory(elements, define_sprite_param
    ("assets/ennemies.png", 3, 3, define_rect(0, 64, 24, 32)));
    temp->move_sprite[1] = sprite_factory(elements, define_sprite_param
    ("assets/ennemies.png", 3, 3, define_rect(0, 96, 24, 32)));
    temp->move_sprite[2] = sprite_factory(elements, define_sprite_param
    ("assets/ennemies.png", 3, 3, define_rect(0, 32, 24, 32)));
    temp->move_sprite[3] = sprite_factory(elements, define_sprite_param
    ("assets/ennemies.png", 3, 3, define_rect(0, 64, 24, 32)));
    temp->move_sprite[4] = sprite_factory(elements, define_sprite_param
    ("assets/ennemies.png", 3, 3, define_rect(0, 0, 24, 32)));
    temp->wich_move = 0;
    for (int i = 0; i < 5; ++i)
        sfSprite_setScale(temp->move_sprite[i]->sprite, define_vectorf(3, 3));
    temp->mov_count = 0;
    temp->rel_pos = define_vectorf(0, 0);
    temp->current_move = define_vectorf(0, 0);
}

aliens_t *init_ennemies(elements_t *elements, int type, sfVector2i pos_on_grid)
{
    aliens_t *temp = malloc(sizeof(aliens_t));

    temp->pos_on_grid = pos_on_grid;
    temp->timer = elements->chrono->ms;
    temp->timer_mov = elements->chrono->ms;
    temp->timer_ind = elements->chrono->ms;
    temp->timer_tot_ind = 0;
    temp->movement = malloc(sizeof(sfVector2f) * 6);
    temp->time_side = malloc(sizeof(int) * 6);
    temp->movement[0] = define_vectorf(0, 0);
    temp->movement[1] = define_vectorf(2, 0);
    temp->movement[2] = define_vectorf(-2, 0);
    temp->movement[3] = define_vectorf(0, 2);
    temp->movement[4] = define_vectorf(0, -2);
    init_ennemies_two(elements, type, pos_on_grid, temp);
    return temp;
}

double distance_point(sfVector2f pa, sfVector2f pb)
{
    return sqrt(((pb.x - pa.x) * (pb.x - pa.x)) + ((pb.y - pa.y) *
    (pb.y - pa.y)));
}


void ennemies_attack(all_t *all, player_t *player, aliens_t *alien,
elements_t *elements)
{
    if (distance_point(define_vectorf(elements->win_size.x / 2,
    elements->win_size.y / 2), alien->pos_on_map) <= 250)
        if (elements->chrono->ms - alien->timer >= 250) {
            all->info.life -= 1;
            alien->timer = elements->chrono->ms;
        }
}

void refresh_alien(elements_t *elements, aliens_t *alien, player_t *player)
{
    int random;

    if (elements->chrono->ms - alien->timer_mov >= 1000) {
        random = rand() % 3;
        if (random == 2)
            alien->wich_move = rand() % 5;
        else
            alien->wich_move = 0;
        alien->current_move = alien->movement[alien->wich_move];
        alien->timer_mov = elements->chrono->ms;
    }
    sfSprite_setPosition(alien->move_sprite[alien->wich_move]->sprite,
    alien->pos_on_map);
    refresh_sprite(alien->move_sprite[alien->wich_move], elements, 0);
}
