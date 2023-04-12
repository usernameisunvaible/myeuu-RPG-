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

void stone_furnace(factory_t *temp, elements_t *elements,
const float bloc_size)
{
    if (temp->type == 1) {
        temp->nb_in = 2;
        temp->in = malloc(sizeof(int) * temp->nb_in);
        temp->in_stack = malloc(sizeof(int) * temp->nb_in);
        for (int i = 0; i < temp->nb_in; ++i) {
            temp->in[i] = 0;
            temp->in_stack[i] = 0;
        }
        temp->fact_sprite = malloc(sizeof(sprite_sheet_t *) * 2);
        temp->fact_sprite[0] = sprite_factory(elements, define_sprite_param
        ("assets/stone_furnace.png", 0, 0, define_rect(0, 0, 133, 133)));
        temp->fact_sprite[1] = sprite_factory(elements, define_sprite_param
        ("assets/stone_furnace_fire.png", 7, 48, define_rect(0, 0, 41, 100)));
        sfSprite_setScale(temp->fact_sprite[0]->sprite, define_vectorf
        ((bloc_size * 100 / 84) / 100, (bloc_size * 100 / 84) / 100));
        sfSprite_setScale(temp->fact_sprite[1]->sprite, define_vectorf
        ((bloc_size * 100 / 84) / 100, (bloc_size * 100 / 84) / 100));
        temp->relative_pos_spr = malloc(sizeof(sfVector2f) * 2);
        temp->relative_pos_spr[0] = define_vectorf((((133 *
        (bloc_size * 100 / 84) / 100) - bloc_size) / 2) * -1, (((133 *
        (bloc_size * 100 / 84) / 100) - bloc_size) / 2) * -1);
        temp->relative_pos_spr[1] = define_vectorf(bloc_size / 2 - (41 *
        (bloc_size * 100 / 84) / 100) / 2, 0);
        temp->out_item = 0;
        temp->process_time = 3300;
        temp->nb_sprite_sheet = 2;
    }
}

void drill(factory_t *temp, elements_t *elements, const float bloc_size)
{
    if (temp->type == 2) {
        temp->nb_in = 2;
        temp->in = malloc(sizeof(int) * temp->nb_in);
        temp->in_stack = malloc(sizeof(int) * temp->nb_in);
        for (int i = 0; i < temp->nb_in; ++i) {
            temp->in[i] = 0;
            temp->in_stack[i] = 0;
        }
        temp->fact_sprite = malloc(sizeof(sprite_sheet_t *) * 1);
        temp->fact_sprite[0] = sprite_factory(elements, define_sprite_param
        ("assets/drill_E.png", 3, 32, define_rect(0, 0, 185, 168)));
        sfSprite_setScale(temp->fact_sprite[0]->sprite, define_vectorf
        ((bloc_size * 100 / 105) / 100, (bloc_size * 100 / 105) / 100));
        temp->relative_pos_spr = malloc(sizeof(sfVector2f) * 1);
        temp->relative_pos_spr[0] = define_vectorf((((145 * (bloc_size *
        100 / 84) / 100) - bloc_size) / 2) * -1, (((140 * (bloc_size * 100
        / 84) / 100) - bloc_size) / 2) * -1);
        temp->out_item = 0;
        temp->process_time = 3300;
        temp->nb_sprite_sheet = 1;
    }
}

void chest(factory_t *temp, elements_t *elements, const float bloc_size)
{
    if (temp->type == 3) {
        temp->nb_in = 10;
        temp->in = malloc(sizeof(int) * temp->nb_in);
        temp->in_stack = malloc(sizeof(int) * temp->nb_in);
        for (int i = 0; i < temp->nb_in; ++i) {
            temp->in[i] = 0;
            temp->in_stack[i] = 0;
        }
        temp->fact_sprite = malloc(sizeof(sprite_sheet_t *) * 1);
        temp->fact_sprite[0] = sprite_factory(elements, define_sprite_param
        ("assets/chest.png", 0, 0, define_rect(0, 0, 64, 80)));
        sfSprite_setScale(temp->fact_sprite[0]->sprite, define_vectorf
        (0.87, 0.87));
        temp->relative_pos_spr = malloc(sizeof(sfVector2f) * 1);
        temp->relative_pos_spr[0] = define_vectorf(0, 0);
        temp->out_item = 0;
        temp->process_time = 0;
        temp->nb_sprite_sheet = 1;
    }
}

void create_fact_one(factory_t *temp, elements_t *elements,
const float bloc_size, char io)
{
    temp->io = io;
    temp->timer_process = elements->chrono->ms;
    temp->timer_out = elements->chrono->ms;
    temp->processing = sfFalse;
    temp->out_stack = 0;

    stone_furnace(temp, elements, bloc_size);
    drill(temp, elements, bloc_size);
    chest(temp, elements, bloc_size);
}
