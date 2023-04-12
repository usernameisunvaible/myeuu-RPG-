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

all_my_fact_t *init_factories(elements_t *elements)
{
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);
    all_my_fact_t *temp = malloc(sizeof(all_my_fact_t));
    temp->counter = 0;
    temp->timer = 0;
    temp->timer_tot = 0;
    temp->factory = malloc(sizeof(factory_t *) * MAP_SIZE_X * MAP_SIZE_Y);
    for (int i = 0; i < MAP_SIZE_X; ++i) {
        for (int j = 0; j < MAP_SIZE_Y; ++j) {
            temp->factory[j * MAP_SIZE_Y + i] = NULL;
        }
    }
    temp->previews = malloc(sizeof(sprite_sheet_t *) * NB_FACT);
    temp->relative_pos_prev = malloc(sizeof(sfVector2f) * NB_FACT);
    temp->previews[0] = sprite_factory(elements, define_sprite_param
    ("assets/stone_furnace_preview.png", 0, 0, define_rect(0, 0, 133, 133)));
    sfSprite_setScale(temp->previews[0]->sprite, define_vectorf
    ((bloc_size * 100 / 84) / 100, (bloc_size * 100 / 84) / 100));
    temp->relative_pos_prev[0] = define_vectorf((((133 * (bloc_size *
    100 / 84) / 100) - bloc_size) / 2) * -1, (((133 * (bloc_size * 100 /
    84) / 100) - bloc_size) / 2) * -1);

    temp->previews[1] = sprite_factory(elements, define_sprite_param
    ("assets/drill_E_preview.png", 3, 32, define_rect(0, 0, 185, 168)));
    sfSprite_setScale(temp->previews[1]->sprite, define_vectorf
    ((bloc_size * 100 / 105) / 100, (bloc_size * 100 / 105) / 100));
    temp->relative_pos_prev[1] = define_vectorf((((145 * (bloc_size * 100 / 84)
    / 100) - bloc_size) / 2) * -1, (((140 * (bloc_size * 100 / 84) / 100) -
    bloc_size) / 2) * -1);

    temp->previews[2] = sprite_factory(elements, define_sprite_param
    ("assets/chest_preview.png", 0, 0, define_rect(0, 0, 64, 80)));
    sfSprite_setScale(temp->previews[2]->sprite, define_vectorf(0.87, 0.87));
    temp->relative_pos_prev[2] = define_vectorf(0, 0);

    temp->colimap = sfImage_create(13478, 14400);
    return temp;
}

factory_t *add_factory(elements_t *elements, structures_t *structures,
sfVector2i pos, int type)
{
    factory_t *temp = malloc(sizeof(factory_t));
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);
    temp->type = type;
    temp->bloc_pos = pos;
    for (int i = (pos.x * bloc_size) + 185; i < (pos.x * bloc_size +
    (int) bloc_size) + 185; ++i) {
        for (int j = (pos.y * bloc_size) + 75; j < (pos.y * bloc_size +
        (int) bloc_size) + 75; ++j) {
            sfImage_setPixel(structures->factories->colimap, i, j,
            sfColor_fromRGB(255, 238, 0));
        }
    }
    create_fact_one(temp, elements, bloc_size, OUT_BOTTOM | IN_TOP);
    structures->factories->factory[pos.y * MAP_SIZE_X + pos.x] = temp;
    return temp;
}

void remove_factory(factory_t *fact)
{
    free_sprite(fact->fact_sprite[0]);
}
