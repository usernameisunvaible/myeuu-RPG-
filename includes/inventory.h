/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** inventory.h
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include "../engine/includes/include_engine.h"
    #include <SFML/Audio.h>

typedef struct infos_player_s {
    int life;
    int armor;
    int coins;
    int play;
}infos_player_t;

typedef struct inventory_s {
    int wood;
    int copper;
    int uranium;
    int iron;
    int coal;
    int iron_plate;
    int copper_plate;
    int on;
    int off;
    int end;
}inventory_t;

typedef struct infos_inventory_s {
    int iron_plate;
    int copper_plate;
    int wood;
    int healing_potion;
    int armor_potion;
}infos_t;

typedef struct laser_s {
    sprite_sheet_t *s_laser;
}laser_t;

typedef struct sprite_s {
    sprite_sheet_t *money_panel;
    sprite_sheet_t *inventory_panel;
    sprite_sheet_t *inventory_box;
    sprite_sheet_t *info_box;
    sprite_sheet_t *info_use_potion;
    sprite_sheet_t *woods;
    sprite_sheet_t *s_uranium;
    sprite_sheet_t *s_coal;
    sprite_sheet_t *s_iron_plate;
    sprite_sheet_t *s_copper_plate;
    sprite_sheet_t *s_healing_potion;
    sprite_sheet_t *s_armor_potion;
    sfVector2f pos_wood;
    sfVector2f pos_iron_plate;
    sfVector2f pos_copper_plate;
    sfVector2f pos_healing_potion;
    sfVector2f pos_armor_potion;
    int on_inventory;
    int check_on;
}sprite_t;

typedef struct my_bool_s {
    sfBool on_wood;
    sfBool on_copper_plate;
    sfBool on_iron_plate;
    sfBool on_healing_potion;
    sfBool on_armor_potion;
}bool_t;

typedef struct all_s {
    laser_t laser;
    sprite_t my_icons;
    inventory_t in;
    infos_player_t info;
    bool_t my_bool;
    infos_t infos_inventory;
    sfFloatRect track_pos_wood;
    sfFloatRect track_pos_copper_plate;
    sfFloatRect track_pos_iron_plate;
    sfFloatRect track_pos_healing_potion;
    sfFloatRect track_pos_armor_potion;
    int nb_icons;
    sfFont *font;
    sfText *t_life;
    sfText *t_armor;
    sfText *t_coins;
    sfText *t_box;
    sfText *t_info;
    sfText *t_info_armor;
    sfText *t_nb_armor;
    sfText *t_nb_healing;
    sfText *t_interaction;
    sfText *t_n_interaction;
    sfText *t_npc;
    sfMusic *drinking_sound;
    sfMusic *delete_sound;
    sfMusic *main_music;
    sfMusic *close_inventory;
    sfMusic *dial_sound_effect;
}all_t;

#endif //INVENTORY_H_
