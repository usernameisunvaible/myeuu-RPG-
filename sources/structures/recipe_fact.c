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

void have_coal(factory_t *fact, int stack, int coal, elements_t *elements)
{
    (fact->in[stack] == 1) ? (fact->out_item = 6) : (0);
    (fact->in[stack] == 2) ? (fact->out_item = 5) : (0);
    if (fact->out_item != 0 && fact->processing == sfFalse &&
    fact->in_stack[stack] >= 2) {
        fact->processing = sfTrue;
        fact->timer_process = elements->chrono->ms;
        fact->in_stack[coal] -= 1;
        fact->in_stack[stack] -= 2;
        (fact->in_stack[0] == 0) ? (fact->in[0] = 0) : (0);
        (fact->in_stack[1] == 0) ? (fact->in[1] = 0) : (0);
    }
}

void drill_mine(factory_t *fact, elements_t *elements, map_t *map)
{
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);
    sfColor color = sfImage_getPixel(map->colormap, fact->bloc_pos.x *
    bloc_size, fact->bloc_pos.y * bloc_size);
    if (fact->type == 2) {
        if (comp_color(color, sfColor_fromRGB(183, 84, 4))) {
            fact->out_item = 1;
            fact->processing = sfTrue;
        }
        if (comp_color(color, sfColor_fromRGB(108, 159, 134))) {
            fact->out_item = 2;
            fact->processing = sfTrue;
        }
        if (comp_color(color, sfColor_fromRGB(108, 159, 134))) {
            fact->out_item = 2;
            fact->processing = sfTrue;
        }
        if (comp_color(color, sfColor_fromRGB(0, 0, 0))) {
            fact->out_item = 4;
            fact->processing = sfTrue;
        }
    }
}

void receipts_fact(factory_t *fact, elements_t *elements, map_t *map)
{
    if (fact->type == 1) {
        if (fact->in[0] == 4 && fact->in_stack[0] >= 1) {
            have_coal(fact, 1, 0, elements);
        }
        if (fact->in[1] == 4 && fact->in_stack[1] >= 1) {
            have_coal(fact, 0, 1, elements);
        }
    }
    drill_mine(fact, elements, map);
}
