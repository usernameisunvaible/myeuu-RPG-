/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** music.c
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

void set_up_music(all_t *all)
{
    all->drinking_sound = sfMusic_createFromFile
    ("assets/sound/drinking_sound.ogg");
    all->delete_sound = sfMusic_createFromFile
    ("assets/sound/delete_sound.ogg");
    all->main_music = sfMusic_createFromFile("assets/sound/main_music.ogg");
    all->close_inventory = sfMusic_createFromFile
    ("assets/sound/open_inventory.ogg");
    all->dial_sound_effect = sfMusic_createFromFile
    ("assets/sound/dial_sound.ogg");
}

void manage_music(all_t *all)
{
    sfMusic_setLoop(all->main_music, sfTrue);
    sfMusic_play(all->main_music);
    sfMusic_setVolume(all->main_music, 15);
    sfMusic_setVolume(all->close_inventory, 30);
    sfMusic_setVolume(all->dial_sound_effect, 30);
    sfMusic_setVolume(all->delete_sound, 20);
    sfMusic_setVolume(all->drinking_sound, 20);
}
