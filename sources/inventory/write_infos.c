/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** inventory_infos.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>
#include <stdio.h>

void my_life(elements_t *elements, all_t *all)
{
    sfVector2f position_text = {530, 390};
    sfText_setPosition(all->t_life, position_text);
    sfText_setString(all->t_life, my_itoa(all->info.life));
    sfRenderWindow_drawText(elements->window, all->t_life, NULL);
}

void my_armor(elements_t *elements, all_t *all)
{
    sfVector2f position_text = {530, 520};
    sfText_setPosition(all->t_armor, position_text);
    sfText_setString(all->t_armor, my_itoa(all->info.armor));
    sfRenderWindow_drawText(elements->window, all->t_armor, NULL);
}

void my_coins(elements_t *elements, all_t *all)
{
    sfVector2f position_text = {1750, 65};
    sfText_setPosition(all->t_coins, position_text);
    sfText_setFont(all->t_coins, all->font);
    sfText_setString(all->t_coins, my_itoa(all->info.coins));
    sfText_setColor(all->t_coins, sfBlack);
    sfRenderWindow_drawText(elements->window, all->t_coins, NULL);
}

void inventory_box(elements_t *elements, all_t *all)
{
    sfVector2f position_text = {980, 160};
    sfText_setPosition(all->t_box, position_text);
    sfText_setString(all->t_box, "Inventory");
    sfText_setColor(all->t_box, sfWhite);
    sfRenderWindow_drawText(elements->window, all->t_box, NULL);
}

void info_healing(elements_t *elements, all_t *all)
{
    sfText_setPosition(all->t_info, define_vectorf(1255, 135));
    sfText_setPosition(all->t_nb_healing, define_vectorf(1255, 200));
    sfText_setFont(all->t_info, all->font);
    sfText_setFont(all->t_nb_healing, all->font);
    sfText_setCharacterSize(all->t_info, 14);
    sfText_setCharacterSize(all->t_nb_healing, 14);
    sfText_setString(all->t_info,
    "This potion give\nyou 20 points of\nlife\nNumber of potion:");
    sfText_setString(all->t_nb_healing,
    my_itoa(all->infos_inventory.healing_potion));
    sfText_setColor(all->t_info, sfWhite);
    sfText_setColor(all->t_nb_healing, sfRed);
    sfRenderWindow_drawText(elements->window, all->t_info, NULL);
    sfRenderWindow_drawText(elements->window, all->t_nb_healing, NULL);
}
