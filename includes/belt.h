/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef BELT_H_
    #define BELT_H_

    #define L 1
    #define R 2
    #define T 3
    #define B 4

    #include "../engine/includes/include_engine.h"

typedef struct belt_s {
    short type;
    sprite_sheet_t *sprite;
    sfVector2f pos;
    int item_pos;
    int item;
    sprite_sheet_t *item_sprite;
    sfVector2f item_size;
    int in;
    int out;
}belt_t;

typedef struct all_belts_s {
    int counter;
    int timer;
    int timer_tot;
    belt_t **belts;
}all_belts_t;

#endif //BELT_H_
