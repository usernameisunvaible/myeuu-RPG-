/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** event.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void set_my_collision(elements_t *elements, sprite_t *sprite, all_t *all)
{
    all->track_pos_wood = sfSprite_getGlobalBounds(sprite->woods->sprite);
    all->track_pos_copper_plate = sfSprite_getGlobalBounds
    (sprite->s_copper_plate->sprite);
    all->track_pos_iron_plate = sfSprite_getGlobalBounds
    (sprite->s_iron_plate->sprite);
    all->track_pos_healing_potion = sfSprite_getGlobalBounds
    (sprite->s_healing_potion->sprite);
    all->track_pos_armor_potion = sfSprite_getGlobalBounds
    (sprite->s_armor_potion->sprite);
    all->my_bool.on_wood = sfFloatRect_contains
    (&all->track_pos_wood, elements->m_pos.x, elements->m_pos.y);
    all->my_bool.on_copper_plate = sfFloatRect_contains
    (&all->track_pos_copper_plate, elements->m_pos.x, elements->m_pos.y);
    all->my_bool.on_iron_plate = sfFloatRect_contains
    (&all->track_pos_iron_plate, elements->m_pos.x, elements->m_pos.y);
    all->my_bool.on_healing_potion = sfFloatRect_contains
    (&all->track_pos_healing_potion, elements->m_pos.x, elements->m_pos.y);
    all->my_bool.on_armor_potion = sfFloatRect_contains
    (&all->track_pos_armor_potion, elements->m_pos.x, elements->m_pos.y);
}

int event(elements_t *elements, sprite_t *sprite, player_t *player, all_t *all)
{
    set_my_collision(elements, sprite, all);
    while (sfRenderWindow_pollEvent(elements->window, &elements->event)) {
        if (elements->event.type == sfEvtClosed)
            sfRenderWindow_close(elements->window);
        manage_event_inventory(elements, sprite);
        event_move_player(elements, player);
        event_move_player2(elements, player);
        if (sprite->on_inventory == 1) {
            set_all_info(elements, sprite, all);
        }
    }
    inventory(elements, sprite, all);
    (all->info.life >= 100) ? (all->info.life = 100) : (0);
    (all->info.life == 0) ? (all->info.play = 1) : (0);
}
