/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** init_hud.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>
#include <stdio.h>

void add_hud(elements_t *elements, my_hud_t *hud)
{
    hud->hp_bar_texture = sfTexture_createFromFile("assets/hud.png", NULL);
    hud->hp_texture = sfTexture_createFromFile("assets/health.png", NULL);
    hud->hp_bar = sfSprite_create();
    hud->hp = sfSprite_create();
    sfSprite_setTexture(hud->hp_bar, hud->hp_bar_texture, sfFalse);
    sfSprite_setTexture(hud->hp, hud->hp_texture, sfFalse);
    sfSprite_setPosition(hud->hp, (sfVector2f){1362, 64});
}

void anim_hp_bar(my_hud_t *hud, all_t *all)
{
    int health = all->info.life;

    sfSprite_setTextureRect(hud->hp, define_rect(0, 0, health * 3, 40));
}
