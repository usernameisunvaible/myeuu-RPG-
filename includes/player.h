/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "../engine/includes/include_engine.h"

    #define MOVE_LEFT 1
    #define MOVE_RIGHT 1 << 1
    #define MOVE_UP 1 << 2
    #define MOVE_DOWN 1 << 3
    #define S_MOVE_LEFT 14
    #define S_MOVE_RIGHT 13
    #define S_MOVE_UP 11
    #define S_MOVE_DOWN 7

    #define G_U player->move & MOVE_UP
    #define G_D player->move & MOVE_DOWN
    #define G_L player->move & MOVE_LEFT
    #define G_R player->move & MOVE_RIGHT

    #define P_SP 4
    #define P_SP_DI 3

typedef struct player_s {
    sfVector2f pos;
    sfVector2f hb_size;
    sprite_sheet_t **idle;
    sfImage *idle_clear;
    sfImage *idle_shadow;
    build_tool_t *editor;
    b_menu_t *b_menu;
    int timer_tot;
    int timer;
    char move;
    sprite_sheet_t **runing;
    sfImage *running_clear;
    sfImage *running_shadow;
    char last_move;
    sfIntRect hit_box;
    int is_on_pause;
    sfBool first_time;
    int skin;
}player_t;

#endif //PLAYER_H_
