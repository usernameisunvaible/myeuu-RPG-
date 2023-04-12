/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** write_infos2.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void info_armor_potion(elements_t *elements, all_t *all)
{
    sfText_setPosition(all->t_info_armor, define_vectorf(1255, 135));
    sfText_setPosition(all->t_nb_armor, define_vectorf(1255, 200));
    sfText_setFont(all->t_info_armor, all->font);
    sfText_setFont(all->t_nb_armor, all->font);
    sfText_setCharacterSize(all->t_info_armor, 14);
    sfText_setCharacterSize(all->t_nb_armor, 14);
    sfText_setString(all->t_info_armor,
    "This potion give\nyou 10 points of\narmor\nNumber of potion:");
    sfText_setString(all->t_nb_armor,
    my_itoa(all->infos_inventory.armor_potion));
    sfText_setColor(all->t_info_armor, sfWhite);
    sfText_setColor(all->t_nb_armor, sfRed);
    sfRenderWindow_drawText(elements->window, all->t_info_armor, NULL);
    sfRenderWindow_drawText(elements->window, all->t_nb_armor, NULL);
}

void info_use_potion(elements_t *elements, all_t *all)
{
    sfText_setPosition(all->t_interaction, define_vectorf(700, 130));
    sfText_setPosition(all->t_n_interaction, define_vectorf(700, 160));
    sfText_setFont(all->t_interaction, all->font);
    sfText_setFont(all->t_n_interaction, all->font);
    sfText_setCharacterSize(all->t_interaction, 14);
    sfText_setCharacterSize(all->t_n_interaction, 14);
    sfText_setString(all->t_interaction, "Press 'E' to use\n");
    sfText_setString(all->t_n_interaction, "Press 'A' to\ndelete\n");
    sfText_setColor(all->t_interaction, sfWhite);
    sfText_setColor(all->t_n_interaction, sfWhite);
    sfRenderWindow_drawText(elements->window, all->t_interaction, NULL);
    sfRenderWindow_drawText(elements->window, all->t_n_interaction, NULL);
}
