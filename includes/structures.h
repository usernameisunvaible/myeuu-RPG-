/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include "../engine/includes/include_engine.h"
    #include "belt.h"

    #define IN_TOP 1
    #define IN_BOTTOM 1 << 1
    #define IN_LEFT 1 << 2
    #define IN_RIGHT 1 << 3
    #define OUT_TOP 1 << 4
    #define OUT_BOTTOM 1 << 5
    #define OUT_LEFT 1 << 6
    #define OUT_RIGHT 1 << 7

    #define NB_FACT 3

    #define MY_FACT structures->factories->factory[ij.y * MAP_SIZE_X + ij.x]

typedef struct factor_param {
    int type;
    char flags;
}factor_params;

typedef struct factory_s {
    int type;
    sprite_sheet_t **fact_sprite;
    sfVector2f pos;
    int out_item;
    int *in;
    int *in_stack;
    int process_time;
    char io;
    sfBool processing;
    int timer_process;
    int out_stack;
    int timer_out;
    int nb_sprite_sheet;
    sfVector2f *relative_pos_spr;
    sfVector2i bloc_pos;
    int nb_in;
}factory_t;

typedef struct all_my_fact_s {
    int counter;
    int timer;
    int timer_tot;
    sprite_sheet_t **previews;
    sfVector2f *relative_pos_prev;
    factory_t **factory;
    sfImage *colimap;
}all_my_fact_t;

typedef struct structures_s {
    all_belts_t *belts;
    all_my_fact_t *factories;
}structures_t;

#endif //STRUCTURES_H_
