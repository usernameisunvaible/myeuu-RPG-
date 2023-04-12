/*
** EPITECH PROJECT, 2021
** npc
** File description:
** npc
*/

#include "../../includes/include_all.h"

int init_dials(npcl_t *npc_l, elements_t *elements, all_t *all)
{
    npc_l->dial = sfSprite_create();
    npc_l->t_dial = sfText_create();
    npc_l->t_name = sfText_create();
    npc_l->last_time = 0;
    sfSprite_setTexture(npc_l->dial, sfTexture_createFromFile(\
    "assets/dials.png", NULL), sfFalse);
    sfSprite_setPosition(npc_l->dial, (sfVector2f){0, 0});
    sfText_setPosition(npc_l->t_dial, (sfVector2f){200, 990});
    sfText_setCharacterSize(npc_l->t_dial, 30);
    sfText_setString(npc_l->t_dial, "nan");
    sfText_setColor(npc_l->t_dial, sfWhite);
    sfText_setFont(npc_l->t_dial, all->font);
    npc_l->t_name = sfText_copy(npc_l->t_dial);
    sfText_setPosition(npc_l->t_name, (sfVector2f){150, 950});
    sfText_setCharacterSize(npc_l->t_name, 19);
}

int show_dials(npcl_t *npc_l, elements_t *elements, npc_t npc, all_t *all)
{
    long actual = sfClock_getElapsedTime(elements->chrono->clock).microseconds;

    if (sfKeyboard_isKeyPressed(sfKeyE) && npc.dialogs[npc_l->current_d + 1] &&
    actual - npc_l->last_time > 500000) {
        sfMusic_stop(all->dial_sound_effect);
        sfMusic_play(all->dial_sound_effect);
        npc_l->last_time = sfClock_getElapsedTime(\
elements->chrono->clock).microseconds;
        npc_l->current_d++;
    }
    sfText_setString(npc_l->t_name, npc.name);
    sfText_setString(npc_l->t_dial, npc.dialogs[npc_l->current_d]);
    sfRenderWindow_drawSprite(elements->window, npc_l->dial, NULL);
    sfRenderWindow_drawText(elements->window, npc_l->t_dial, NULL);
    sfRenderWindow_drawText(elements->window, npc_l->t_name, NULL);
}

int npc_prox(npcl_t *npc_l, elements_t *elements, all_t *all)
{
    sfVector2f pos;
    int state = 0;
    for (int i = 0; i < npc_l->nb_npcs; i++) {
        pos = sfSprite_getPosition(npc_l->npcs[i].sprite->sprite);
        if (pos.x > 800 && pos.x < 1100 && pos.y > 400 && pos.y < 700) {
            show_dials(npc_l, elements, npc_l->npcs[i], all);
            state = 1;
        }
    }
    if (state == 0)
        npc_l->current_d = 0;
}
