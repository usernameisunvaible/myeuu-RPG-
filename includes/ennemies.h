/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef ENNEMIES_H_
    #define ENNEMIES_H_

    #include "../engine/includes/include_engine.h"

typedef struct aliens_s {
    sfVector2i pos_on_grid;
    sfVector2f pos_on_map;
    int timer;
    sfVector2f *movement;
    int *time_side;
    int timer_mov;
    int mov_count;
    sfVector2f rel_pos;
    int timer_ind;
    int timer_tot_ind;
    sfVector2f current_move;
    sprite_sheet_t **move_sprite;
    int wich_move;
}aliens_t;

#endif //ENNEMIES_H_
