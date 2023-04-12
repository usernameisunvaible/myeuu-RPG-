/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** hud.h
*/

#ifndef HUD_H_
    #define HUD_H_

    #include "../engine/includes/include_engine.h"

typedef struct my_hud_s {
    sfTexture *hp_bar_texture;
    sfSprite *hp_bar;
    sfTexture *hp_texture;
    sfSprite *hp;
}my_hud_t;

typedef struct {
    int open;
    long last_time;
    sfSprite *menu;
    button_t *resume;
    button_t *quit;
    button_t *back;
} pause_m_t;

#endif //HUD_H_
