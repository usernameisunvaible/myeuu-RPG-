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

build_obj_t *init_object(elements_t *elements, int type, sprite_param_t para)
{
    build_obj_t *obj = malloc(sizeof(build_obj_t));
    const float bloc_size = (elements->win_size.y * (BLOC_PERCENTIL) / 100);

    obj->obj = type;
    obj->preview = sprite_factory(elements, para);
    sfSprite_setScale(obj->preview->sprite, define_vectorf((bloc_size * 100 /
    32) / 100, (bloc_size * 100 / 32) / 100));
    return obj;
}

build_tool_t *init_editor(elements_t *elements)
{
    build_tool_t *temp = malloc(sizeof(build_tool_t));

    temp->isactive = sfFalse;
    temp->obj = 0;
    temp->all_object = malloc(sizeof(build_obj_t *) * NB_OBJ + 1);
    for (int i = 0; i < 12; ++i) {
        temp->all_object[i] = init_object(elements, 1, define_sprite_param(
    "assets/belt_preview.png", 15, 16, define_rect(0, (i) * 32, 32,
    32)));
    }
    return temp;
}

void refresh_editor(build_tool_t *editor, elements_t *elements,
player_t *player, structures_t *structures)
{

    if (editor->isactive) {
        if (player->editor->obj <= 11)
            put_belt(editor, elements, player, structures);
        if (player->editor->obj > 11) {
            put_structure(editor, elements, player, structures);
        }
    }
}
