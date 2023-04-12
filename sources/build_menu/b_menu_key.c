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

int build_menu_key(player_t *player, elements_t *elements)
{
    if (OPEN_B_MENU == KEY_CODE) {
        if (player->b_menu->is_active) {
            player->b_menu->is_active = sfFalse;
            return 0;
        }
        if (player->editor->isactive == sfFalse) {
            player->b_menu->is_active = sfTrue;
            return 0;
        }
        if (player->editor->isactive) {
            player->editor->isactive = sfFalse;
            return 0;
        }
    }
}
