/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>
#include <stdio.h>

void set_item_pos_five(belt_t *temp, const float bloc_size)
{
    if (temp->type == 11)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), ((temp->pos.y +
bloc_size) - temp->item_size.y / 2) - ((bloc_size / 32) * (temp->item_pos))));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size) - temp->item_size.x / 2) - ((bloc_size / 32) * (
temp->item_pos)), (temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
    if (temp->type == 12)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), ((temp->pos.y +
bloc_size) - temp->item_size.y / 2) - ((bloc_size / 32) * (temp->item_pos))));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(
bloc_size / 32 * temp->item_pos + temp->pos.x - temp->item_size.x / 2, (
temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
}

void set_item_pos_four(belt_t *temp, const float bloc_size)
{
    if (temp->type == 9)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(
bloc_size / 32 * temp->item_pos + temp->pos.x - temp->item_size.x / 2, (
temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), ((temp->pos.y +
bloc_size) - temp->item_size.y / 2) - ((bloc_size / 32) * (temp->item_pos))));
    if (temp->type == 10)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(
bloc_size / 32 * temp->item_pos + temp->pos.x - temp->item_size.x / 2, (
temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), bloc_size / 32 *
temp->item_pos + temp->pos.y - temp->item_size.y / 2));
    set_item_pos_five(temp, bloc_size);
}

void set_item_pos_three(belt_t *temp, const float bloc_size)
{
    if (temp->type == 7)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), bloc_size / 32 *
temp->item_pos + temp->pos.y - temp->item_size.y / 2));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(
bloc_size / 32 * temp->item_pos + temp->pos.x - temp->item_size.x / 2, (
temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
    if (temp->type == 8)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), bloc_size / 32 *
temp->item_pos + temp->pos.y - temp->item_size.y / 2));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size) - temp->item_size.x / 2) - ((bloc_size / 32) * (
temp->item_pos)), (temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
    set_item_pos_four(temp, bloc_size);
}

void set_item_pos_two(belt_t *temp, const float bloc_size)
{
    if (temp->type == 5)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size) - temp->item_size.x / 2) - ((bloc_size / 32) * (
temp->item_pos)), (temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), ((temp->pos.y +
bloc_size) - temp->item_size.y / 2) - ((bloc_size / 32) * (temp->item_pos))));
    if (temp->type == 6)
        if (temp->item_pos <= 16)
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size) - temp->item_size.x / 2) - ((bloc_size / 32) * (
temp->item_pos)), (temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
        else
            sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), bloc_size / 32 *
temp->item_pos + temp->pos.y - temp->item_size.y / 2));
    set_item_pos_three(temp, bloc_size);
}

void set_item_pos(belt_t *temp, elements_t *elements)
{
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);

    if (temp->type == 1)
        sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(
bloc_size / 32 * temp->item_pos + temp->pos.x - temp->item_size.x / 2, (
temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
    if (temp->type == 2)
        sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size) - temp->item_size.x / 2) - ((bloc_size / 32) * (
temp->item_pos)), (temp->pos.y + bloc_size / 2 ) - temp->item_size.y / 2));
    if (temp->type == 3)
        sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), ((temp->pos.y +
bloc_size) - temp->item_size.y / 2) - ((bloc_size / 32) * (temp->item_pos))));
    if (temp->type == 4)
        sfSprite_setPosition(temp->item_sprite->sprite, define_vectorf(((
temp->pos.x + bloc_size / 2 ) - temp->item_size.x / 2), bloc_size / 32 *
temp->item_pos + temp->pos.y - temp->item_size.y / 2));
    set_item_pos_two(temp, bloc_size);
}
