/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** manage_potion.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void use_potion(elements_t *elements, sprite_t *sprite, all_t *all)
{
    if (elements->event.type == sfEvtKeyPressed && sfKeyE ==
    elements->event.key.code && all->my_bool.on_healing_potion ==
    sfTrue && all->info.life < 100) {
        sfMusic_stop(all->drinking_sound);
        sfMusic_play(all->drinking_sound);
        all->info.life += 20;
        all->infos_inventory.healing_potion -= 1;
    }
    if (elements->event.type == sfEvtKeyPressed && sfKeyE ==
    elements->event.key.code && all->my_bool.on_armor_potion ==
    sfTrue && all->info.armor < 50) {
        sfMusic_stop(all->drinking_sound);
        sfMusic_play(all->drinking_sound);
        all->info.armor += 10;
        all->infos_inventory.armor_potion -= 1;
    }
}

void delete_potion(elements_t *elements, sprite_t *sprite, all_t *all)
{
    if (elements->event.type == sfEvtKeyPressed && sfKeyA ==
    elements->event.key.code && all->my_bool.on_healing_potion == sfTrue) {
        sfMusic_stop(all->delete_sound);
        sfMusic_play(all->delete_sound);
        all->infos_inventory.healing_potion -= 1;
    }
    if (elements->event.type == sfEvtKeyPressed && sfKeyA ==
    elements->event.key.code && all->my_bool.on_armor_potion == sfTrue) {
        sfMusic_stop(all->delete_sound);
        sfMusic_play(all->delete_sound);
        all->infos_inventory.armor_potion -= 1;
    }
}
