/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** event_inventory.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdio.h>

void manage_event_inventory(elements_t *elements, sprite_t *sprite)
{
    if (elements->event.type == sfEvtKeyReleased && sfKeyI ==
    elements->event.key.code && sprite->on_inventory == 0) {
        sprite->on_inventory = 1;
        sprite->check_on = 2;
    }
    if (elements->event.type == sfEvtKeyReleased && sfKeyI ==
    elements->event.key.code && sprite->on_inventory == 1
    && sprite->check_on != 2)
        sprite->on_inventory = 0;
    if (elements->event.type == sfEvtKeyReleased && sfKeyI ==
    elements->event.key.code && sprite->check_on == 2) {
        sprite->on_inventory = 1;
        sprite->check_on = 0;
    }
}

void cond_draw_icon(elements_t *elements, sprite_t *sprite, all_t *all)
{
    (all->in.wood == 1) ? refresh_sprite(sprite->woods, elements, 0) : (0);
    (all->in.copper_plate == 1) ? refresh_sprite
    (sprite->s_copper_plate, elements, 0) : (0);
    (all->in.iron_plate == 1) ? refresh_sprite
    (sprite->s_iron_plate, elements, 0) : (0);
    (all->infos_inventory.healing_potion >= 1) ? refresh_sprite
    (sprite->s_healing_potion, elements, 0) : (0);
    (all->infos_inventory.armor_potion >= 1) ? refresh_sprite
    (sprite->s_armor_potion, elements, 0) : (0);
    (all->infos_inventory.healing_potion == 0) ? sfSprite_setPosition
    (sprite->s_healing_potion->sprite, define_vectorf(2500, 2000)) : (0);
    (all->infos_inventory.armor_potion == 0) ? sfSprite_setPosition
    (sprite->s_armor_potion->sprite, define_vectorf(2550, 2010)) : (0);
}

void draw_info_inventory(elements_t *elements, sprite_t *sprite, all_t *all)
{
    if (all->my_bool.on_healing_potion == sfTrue) {
        refresh_sprite(sprite->info_box, elements, 0);
        refresh_sprite(sprite->info_use_potion, elements, 0);
        info_healing(elements, all);
        info_use_potion(elements, all);
    }
    if (all->my_bool.on_armor_potion == sfTrue) {
        refresh_sprite(sprite->info_box, elements, 0);
        refresh_sprite(sprite->info_use_potion, elements, 0);
        info_armor_potion(elements, all);
        info_use_potion(elements, all);
    }
}

void inventory(elements_t *elements, sprite_t *sprite, all_t *all)
{

    if (sprite->on_inventory == 1) {
        sfMusic_stop(all->close_inventory);
        sfMusic_play(all->close_inventory);
        sfRenderWindow_setMouseCursorVisible(elements->window, sfTrue);
        refresh_sprite(sprite->inventory_box, elements, 0);
        refresh_sprite(sprite->inventory_panel, elements, 0);
        my_life(elements, all);
        my_armor(elements, all);
        inventory_box(elements, all);
        cond_draw_icon(elements, sprite, all);
        draw_info_inventory(elements, sprite, all);
    }
}
