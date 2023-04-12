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

sfVector2f temp(sfVector2i ij, elements_t *elements, sfVector2f p_pos,
sfVector2f rel_pos)
{
    sfVector2f temp;
    const float bloc_size = (elements->win_size.y * (BLOC_PERCENTIL) / 100);

    temp = define_vectorf(((ij.x * (elements->win_size.y * BLOC_PERCENTIL /
    100) - (p_pos.x - elements->win_size.x / 2)) + ij.x) + rel_pos.x,
    ((ij.y * ( elements->win_size.y * BLOC_PERCENTIL / 100) - (p_pos.y -
    elements->win_size.y / 2)) + ij.y) + rel_pos.y);
    return temp;
}

void put_belt(build_tool_t *editor, elements_t *elements,
player_t *player, structures_t *structures)
{
    const float bloc_size = (elements->win_size.y * (BLOC_PERCENTIL) / 100);
    sfVector2i pos;

    pos = define_vectori((elements->m_pos.x + (player->pos.x - ((int)
    elements->win_size.x / 2))) / (int)(bloc_size), (elements->m_pos.y + (
    player->pos.y - ((int)elements->win_size.y / 2))) / (int)(bloc_size));
    sfSprite_setPosition(editor->all_object[editor->obj]->preview->sprite,
    temp(pos, elements, player->pos, define_vectorf(0, 0)));
    refresh_sprite(editor->all_object[editor->obj]->preview, elements, 0);
    if (elements->left && structures->belts->belts[pos.y * MAP_SIZE_Y + pos.x]
    == NULL && structures->factories->factory [pos.y * MAP_SIZE_Y + pos.x] ==
    NULL)
        add_belt(player->editor->obj + 1,
        elements, structures->belts->belts, pos);
    if (elements->right && structures->belts->belts
    [pos.y * MAP_SIZE_Y + pos.x] != NULL) {
        del_belt(structures->belts->belts[pos.y * MAP_SIZE_Y + pos.x]);
        structures->belts->belts[pos.y * MAP_SIZE_Y + pos.x] = NULL;
    }
}

void put_structure(build_tool_t *editor, elements_t *elements,
player_t *player, structures_t *structures)
{
    const float bloc_size = (elements->win_size.y * (BLOC_PERCENTIL) / 100);
    sfVector2i pos;

    pos = define_vectori((elements->m_pos.x + (player->pos.x - ((int)
    elements->win_size.x / 2))) / (int)(bloc_size), (elements->m_pos.y + (
    player->pos.y - ((int)elements->win_size.y / 2))) / (int)(bloc_size));
    sfSprite_setPosition(structures->factories->previews
    [player->editor->obj - 12]->sprite,
    temp(pos, elements, player->pos, structures->factories->relative_pos_prev
    [player->editor->obj - 12]));
    refresh_sprite(structures->factories->previews[player->editor->obj - 12],
    elements, 0);
    if (elements->left && structures->belts->belts[pos.y * MAP_SIZE_Y + pos.x]
    == NULL && structures->factories->factory [pos.y * MAP_SIZE_Y + pos.x] ==
    NULL)
    add_factory(elements, structures, pos, player->editor->obj - 11);
}
