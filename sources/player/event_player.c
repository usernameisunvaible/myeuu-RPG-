/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** event_player.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void event_move_player(elements_t *elements, player_t *player)
{
    if (elements->event.type == sfEvtKeyPressed) {
        (K_UP == KEY_CODE) ? (player->move = player->move | MOVE_UP) :
        (0);
        (K_DOWN == KEY_CODE) ? (player->move = player->move | MOVE_DOWN) :
        (0);
        (K_LEFT == KEY_CODE) ? (player->move = player->move | MOVE_LEFT) :
        (0);
        (K_RIGHT == KEY_CODE) ? (player->move = player->move | MOVE_RIGHT)
        : (0);
        build_menu_key(player, elements);
    }
}

void event_move_player2(elements_t *elements, player_t *player)
{
    if (elements->event.type == sfEvtKeyReleased) {
        (K_UP == KEY_CODE) ? (player->move = player->move & S_MOVE_UP) :
        (0);
        (K_DOWN == KEY_CODE) ? (player->move = player->move & S_MOVE_DOWN) :
        (0);
        (K_LEFT == KEY_CODE) ? (player->move = player->move & S_MOVE_LEFT) :
        (0);
        (K_RIGHT == KEY_CODE) ?
        (player->move = player->move & S_MOVE_RIGHT) : (0);
    }
}
