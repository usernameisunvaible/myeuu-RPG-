/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** init_inventory.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>
#include <stdio.h>

void add_inventory(elements_t *elements, sprite_t *sprite)
{
    sprite->inventory_panel = sprite_factory(elements, define_sprite_param
    ("assets/inventory.png", 0, 0, define_rect(0, 0, 270, 135)));
    sprite->inventory_box = sprite_factory(elements, define_sprite_param
    ("assets/inventory_box.png", 0, 0, define_rect(0, 0, 200, 50)));
    sprite->info_box = sprite_factory(elements, define_sprite_param
    ("assets/info_box.png", 0, 0, define_rect(0, 0, 82, 50)));
    sprite->info_use_potion = sprite_factory(elements, define_sprite_param
    ("assets/info_box.png", 0, 0, define_rect(0, 0, 82, 50)));
    sfSprite_setScale(sprite->inventory_panel->sprite, define_vectorf(4, 4));
    sfSprite_setScale(sprite->inventory_box->sprite, define_vectorf(2, 2));
    sfSprite_setScale(sprite->info_box->sprite, define_vectorf(2, 2));
    sfSprite_setScale(sprite->info_use_potion->sprite, define_vectorf(2, 2));
    sfSprite_setPosition(sprite->inventory_panel->sprite, define_vectorf
    (370, 220));
    sfSprite_setPosition(sprite->inventory_box->sprite, define_vectorf
    (850, 130));
    sfSprite_setPosition(sprite->info_box->sprite, define_vectorf
    (1250, 125));
    sfSprite_setPosition(sprite->info_use_potion->sprite, define_vectorf
    (690, 125));
}

void add_icon(elements_t *elements, sprite_t *sprite)
{
    sprite->woods = sprite_factory(elements, define_sprite_param
    ("assets/wood.png", 0, 0, define_rect(0, 0, 60, 60)));
    sprite->s_copper_plate = sprite_factory(elements, define_sprite_param
    ("assets/icon.png", 0, 0, define_rect(0, 310, 60, 310)));
    sprite->s_iron_plate = sprite_factory(elements, define_sprite_param
    ("assets/icon.png", 0, 0, define_rect(0, 250, 60, 60)));
    sprite->s_healing_potion = sprite_factory(elements, define_sprite_param
    ("assets/healing_potion.png", 0, 0, define_rect(0, 0, 60, 60)));
    sprite->s_armor_potion = sprite_factory(elements, define_sprite_param
    ("assets/armor_potion.png", 0, 0, define_rect(360, 0, 80, 60)));
    sfSprite_setPosition(sprite->woods->sprite, define_vectorf
    (700, 260));
    sfSprite_setPosition(sprite->s_copper_plate->sprite, define_vectorf
    (825, 260));
    sfSprite_setPosition(sprite->s_iron_plate->sprite, define_vectorf
    (955, 265));
    sfSprite_setPosition(sprite->s_healing_potion->sprite, define_vectorf
    (1085, 265));
    sfSprite_setPosition(sprite->s_armor_potion->sprite, define_vectorf
    (1195, 265));
}
