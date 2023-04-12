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

int extract_item(structures_t *structures, sfVector2i ij, elements_t *elements,
int belt)
{
    if (structures->belts->belts[belt]->item_pos == 0 &&
    MY_FACT->out_item != 0) {
        if (elements->chrono->ms - MY_FACT->timer_out >= 1100 &&
        MY_FACT->out_stack > 0 ) {
            structures->belts->belts[belt]->item = 0;
            put_item_on_belt(structures->belts->belts[belt],
            MY_FACT->out_item, elements);
            MY_FACT->timer_out = elements->chrono->ms;
            MY_FACT->out_stack -= 1;
        }
    }
}

int chest_treat(structures_t *structures, sfVector2i ij)
{
    for (int i = 0; i < MY_FACT->nb_in; ++i) {
        if (MY_FACT->in[i] != 0) {
            MY_FACT->out_item = MY_FACT->in[i];
            MY_FACT->out_stack = MY_FACT ->in_stack[i];
            MY_FACT->in[i] = 0;
            MY_FACT->in_stack[i] = 0;
            return 0;
        }
    }
}

void refresh_out_fact(structures_t *structures, sfVector2i ij,
elements_t *elements)
{
    const int pos_n = ij.y * MAP_SIZE_X + ij.x;
    int add = 0;
    int br = 0;

    for (int i = 0; i < 4; ++i) {
        (i == 0) ? (add = 1) : (0);
        (i == 1) ? (add = -1) : (0);
        (i == 2) ? (add = MAP_SIZE_X) : (0);
        (i == 3) ? (add = -MAP_SIZE_X) : (0);
        if (structures->belts->belts[pos_n + add] &&
        structures->belts->belts[pos_n + add]->in == i + 1) {
            br = extract_item(structures, ij, elements, pos_n + add);
        }
        if (br != 0)
            break;
    }
    if (MY_FACT->type == 3 && MY_FACT->out_stack == 0)
        chest_treat(structures, ij);
    if (elements->chrono->ms - MY_FACT->timer_process >=
    MY_FACT->process_time && MY_FACT->processing) {
        MY_FACT->out_stack += 1;
        MY_FACT->timer_process = elements->chrono->ms;
        MY_FACT->processing = sfFalse;
    }
}
