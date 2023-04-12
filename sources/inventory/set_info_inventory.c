/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** set_info_inventory.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void set_all_info(elements_t *elements, sprite_t *sprite, all_t *all)
{
    (all->my_bool.on_wood == sfTrue) ? event_drag_n_drop_wood
    (elements, sprite, all) : (0);
    (all->my_bool.on_copper_plate == sfTrue) ? event_drag_n_drop_copper_plate
    (elements, sprite, all) : (0);
    (all->my_bool.on_iron_plate == sfTrue) ? event_drag_n_drop_iron_plate
    (elements, sprite, all) : (0);
    if (all->my_bool.on_healing_potion == sfTrue) {
        event_drag_n_drop_healing_potion(elements, sprite, all);
        use_potion(elements, sprite, all);
        delete_potion(elements, sprite, all);
    }
    if (all->my_bool.on_armor_potion == sfTrue) {
        event_drag_n_drop_armor_potion(elements, sprite, all);
        use_potion(elements, sprite, all);
        delete_potion(elements, sprite, all);
    }
}
