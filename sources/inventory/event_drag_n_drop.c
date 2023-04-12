/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** event__n_drop.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void event_drag_n_drop_wood(elements_t *elements, sprite_t *sprite, all_t *all)
{
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.end != 3) {
        all->in.on = 1;
        all->in.off = 2;
        all->in.end = 3;
    }
    if (elements->event.type == sfEvtMouseMoved && all->in.on == 1 &&
    all->in.wood == 1) {
        sprite->pos_wood.x = elements->m_pos.x - 30;
        sprite->pos_wood.y = elements->m_pos.y - 30;
        sfSprite_setPosition(sprite->woods->sprite, sprite->pos_wood);
        all->in.off = 0;
    }
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.off != 2) {
        sprite->pos_wood.x = elements->m_pos.x - 30;
        sprite->pos_wood.y = elements->m_pos.y - 30;
        all->in.on = 0;
        all->in.off = 0;
        all->in.end = 0;
    }
}

void event_drag_n_drop_copper_plate(elements_t *elements, sprite_t *sprite,
all_t *all)
{
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.end != 33) {
        all->in.on = 11;
        all->in.off = 22;
        all->in.end = 33;
    }
    if (elements->event.type == sfEvtMouseMoved && all->in.on == 11 &&
    all->in.copper_plate == 1) {
        sprite->pos_copper_plate.x = elements->m_pos.x - 30;
        sprite->pos_copper_plate.y = elements->m_pos.y - 30;
        sfSprite_setPosition
        (sprite->s_copper_plate->sprite, sprite->pos_copper_plate);
        all->in.off = 0;
    }
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.off != 22) {
        sprite->pos_copper_plate.x = elements->m_pos.x - 30;
        sprite->pos_copper_plate.y = elements->m_pos.y - 30;
        all->in.on = 0;
        all->in.off = 0;
        all->in.end = 0;
    }
}

void event_drag_n_drop_iron_plate(elements_t *elements, sprite_t *sprite,
all_t *all)
{
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.end != 6) {
        all->in.on = 4;
        all->in.off = 5;
        all->in.end = 6;
    }
    if (elements->event.type == sfEvtMouseMoved && all->in.on == 4 &&
    all->in.iron_plate == 1) {
        sprite->pos_iron_plate.x = elements->m_pos.x - 30;
        sprite->pos_iron_plate.y = elements->m_pos.y - 30;
        sfSprite_setPosition
        (sprite->s_iron_plate->sprite, sprite->pos_iron_plate);
        all->in.off = 0;
    }
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.off != 5) {
        sprite->pos_iron_plate.x = elements->m_pos.x - 30;
        sprite->pos_iron_plate.y = elements->m_pos.y - 30;
        all->in.on = 0;
        all->in.off = 0;
        all->in.end = 0;
    }
}

void event_drag_n_drop_healing_potion(elements_t *elements, sprite_t *sprite,
all_t *all)
{
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.end != 9) {
        all->in.on = 7;
        all->in.off = 8;
        all->in.end = 9;
    }
    if (elements->event.type == sfEvtMouseMoved && all->in.on == 7 &&
    all->infos_inventory.healing_potion >= 1) {
        sprite->pos_healing_potion.x = elements->m_pos.x - 30;
        sprite->pos_healing_potion.y = elements->m_pos.y - 30;
        sfSprite_setPosition
        (sprite->s_healing_potion->sprite, sprite->pos_healing_potion);
        all->in.off = 0;
    }
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.off != 8) {
        sprite->pos_healing_potion.x = elements->m_pos.x - 30;
        sprite->pos_healing_potion.y = elements->m_pos.y - 30;
        all->in.on = 0;
        all->in.off = 0;
        all->in.end = 0;
    }
}

void event_drag_n_drop_armor_potion(elements_t *elements, sprite_t *sprite,
all_t *all)
{
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.end != 14) {
        all->in.on = 12;
        all->in.off = 13;
        all->in.end = 14;
    }
    if (elements->event.type == sfEvtMouseMoved && all->in.on == 12 &&
    all->infos_inventory.armor_potion >= 1) {
        sprite->pos_armor_potion.x = elements->m_pos.x - 50;
        sprite->pos_armor_potion.y = elements->m_pos.y - 40;
        sfSprite_setPosition
        (sprite->s_armor_potion->sprite, sprite->pos_armor_potion);
        all->in.off = 0;
    }
    if (elements->event.type == sfEvtMouseButtonPressed && all->in.off != 13) {
        sprite->pos_armor_potion.x = elements->m_pos.x - 50;
        sprite->pos_armor_potion.y = elements->m_pos.y - 40;
        all->in.on = 0;
        all->in.off = 0;
        all->in.end = 0;
    }
}
