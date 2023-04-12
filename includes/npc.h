/*
** EPITECH PROJECT, 2022
** n
** File description:
** n
*/

#ifndef NEED_H_
    #define NEED_H_

    #include "../engine/includes/include_engine.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct {
    char *name;
    char **dialogs;
    char pos_x;
    char pos_y;
    sprite_sheet_t *sprite;
} npc_t;

typedef struct {
    npc_t *npcs;
    int nb_npcs;
    sfSprite *dial;
    sfText *t_dial;
    sfText *t_name;
    int current_d;
    long last_time;
} npcl_t;
char **my_str_to_word_array(char *str, char l);
int init_npcs(npcl_t *npc_l, elements_t *elements);
int init_dials(npcl_t *npc_l, elements_t *elements, all_t *all);
int show_dials(npcl_t *npc_l, elements_t *elements, npc_t npc, all_t *all);
int npc_prox(npcl_t *npc_l, elements_t *elements, all_t *all);

#endif
