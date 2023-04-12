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

int input_fact(structures_t *structures, elements_t *elements,
sfVector2i ij, sfVector2i b_id)
{
    if (MY_FACT->in[(b_id.y == 1) ? (0): (1)] ==
    structures->belts->belts[b_id.x]->item)
        return 1;
    if (MY_FACT->in[b_id.y] == 0 || MY_FACT->in[b_id.y] ==
    structures->belts->belts[b_id.x]->item) {
        MY_FACT->in[b_id.y] = structures->belts->belts[b_id.x]->item;
        MY_FACT->in_stack[b_id.y] += 1;
        free_sprite(structures->belts->belts[b_id.x]->item_sprite);
        structures->belts->belts[b_id.x]->item_sprite = NULL;
        structures->belts->belts[b_id.x]->item_pos = 0;
        structures->belts->belts[b_id.x]->item = 0;
        return 0;
    }
    return 1;
}

int already_in(structures_t *structures, elements_t *elements, sfVector2i ij,
int belt)
{
    for (int i = 0; i < MY_FACT->nb_in; ++i) {
        if (structures->belts->belts[belt]->item == MY_FACT->in[i]) {
            MY_FACT->in_stack[i] += 1;
            free_sprite(structures->belts->belts[belt]->item_sprite);
            structures->belts->belts[belt]->item_sprite = NULL;
            structures->belts->belts[belt]->item_pos = 0;
            structures->belts->belts[belt]->item = 0;
            return 1;
        }
    }
    return 0;
}

int get_item_from_belt(structures_t *structures, elements_t *elements,
sfVector2i ij, int belt)
{
    int temp = 0;
    if (structures->belts->belts[belt]->item_pos == 32) {
        temp = already_in(structures, elements, ij, belt);
        if (temp == 0) {
            for (int i = 0; i < MY_FACT->nb_in; ++i) {
                if (MY_FACT->in[i] == 0) {
                    MY_FACT->in[i] = structures->belts->belts[belt]->item;
                    MY_FACT->in_stack[i] += 1;
                    free_sprite(structures->belts->belts[belt]->item_sprite);
                    structures->belts->belts[belt]->item_sprite = NULL;
                    structures->belts->belts[belt]->item_pos = 0;
                    structures->belts->belts[belt]->item = 0;
                    return 0;
                }
            }
        }
    return 0;
    }
}

void get_item_fact(structures_t *structures, elements_t *elements,
sfVector2i ij)
{
    const int pos_n = ij.y * MAP_SIZE_X + ij.x;
    int add = 0;
    int out = 0;
    for (int i = 0; i < 4; ++i) {
        (i == 0) ? (add = 1) : (0);
        (i == 0) ? (out = 2) : (0);
        (i == 1) ? (add = -1) : (0);
        (i == 1) ? (out = 1) : (0);
        (i == 2) ? (add = MAP_SIZE_X) : (0);
        (i == 2) ? (out = 4) : (0);
        (i == 3) ? (add = -MAP_SIZE_X) : (0);
        (i == 3) ? (out = 3) : (0);

        if (structures->belts->belts[pos_n + add] &&
        structures->belts->belts[pos_n + add]->out == out) {
            get_item_from_belt(structures, elements, ij, pos_n + add);
        }
    }
}
