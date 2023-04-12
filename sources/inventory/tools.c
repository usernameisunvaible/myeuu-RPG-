/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** tools.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>
#include <stdio.h>

char *my_itoa(int nb)
{
    int len;
    char *str;
    int tmp;

    if (nb == 0)
        return ("0");
    tmp = nb;
    len = 0;
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    str = malloc(sizeof(str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}

void set_up_var(sprite_t *sprite, all_t *all)
{
    sprite->on_inventory = 0;
    sprite->check_on = 0;
    all->info.coins = 10;
    all->info.life = 100;
    all->info.armor = 50;
    all->infos_inventory.armor_potion = 4;
    all->infos_inventory.healing_potion = 4;
    all->in.on = 0;
    all->in.off = 0;
    all->in.end = 0;
    all->in.wood = 1;
    all->in.coal = 0;
    all->in.uranium = 0;
    all->in.copper_plate = 1;
    all->in.iron_plate = 1;
    all->info.play = 1;
}

void my_hud(elements_t *elements, all_t *all, my_hud_t *hud)
{
    sfRenderWindow_drawSprite(elements->window, hud->hp_bar, NULL);
    sfRenderWindow_drawSprite(elements->window, hud->hp, NULL);
    anim_hp_bar(hud, all);
    my_coins(elements, all);
}

void set_font(all_t *all)
{
    sfText **texts[] = {&all->t_box, &all->t_coins, &all->t_armor,
    &all->t_life, &all->t_info, &all->t_info_armor, &all->t_nb_armor,
    &all->t_nb_healing, &all->t_interaction, &all->t_n_interaction,
    &all->t_npc, 0};
    all->font = sfFont_createFromFile("assets/space.otf");

    for (int i = 0; texts[i]; i++) {
        *texts[i] = sfText_create();
        sfText_setFont(*texts[i], all->font);
        sfText_setColor(*texts[i], sfWhite);
    }
}

void add_full(elements_t *elements, sprite_t *sprite, my_hud_t *hud,
all_t *all)
{
    add_inventory(elements, sprite);
    add_icon(elements, sprite);
    add_hud(elements, hud);
    set_up_var(sprite, all);
    set_font(all);
    set_up_music(all);
    manage_music(all);
}
