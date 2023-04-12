/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"
#include <stdlib.h>

void init_player_two(elements_t *elements, player_t *player, int skin)
{
    player->editor = init_editor(elements);
    player->b_menu = init_build_menu(elements);
    player->timer = 0;
    player->timer_tot = 0;
    player->move = 0;
    player->last_move = 4;
    player->pos = define_vectorf(9416, 3840);
    player->idle_shadow = sfImage_create(1562, 720);
    sfImage_copyImage(player->idle_shadow, player->idle_clear, 0, 0,
    define_rect(0, 0, 1562, 720), sfFalse);
    player->running_shadow = sfImage_create(1496, 816);
    sfImage_copyImage(player->running_shadow, player->running_clear, 0, 0,
    define_rect(0, 0, 1496, 816), sfFalse);
    player->first_time = sfFalse;
    player->skin = skin;
}

player_t *init_player(elements_t *elements, player_t *player, int skin)
{
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);
    char *skins_running[] = {"assets/running.png", "assets/runningred.png",
    "assets/runningblue.png", "assets/runninglgbt.png"};
    char *skins_idle[] = {"assets/idle.png", "assets/idlered.png",
    "assets/idleblue.png", "assets/idlelgbt.png"};

    player->pos = define_vectorf(elements->win_size.x / 2,
    elements->win_size.y / 2);
    player->runing = malloc(sizeof(sprite_sheet_t *) * 8);
    player->hb_size = define_vectorf(68, 102);
    player->hit_box = define_rect(15, 25, 27, 50);
    for (int i = 0; i < 8; ++i) {
        player->runing[i] = sprite_factory(elements, define_sprite_param
        (skins_running[skin - 1], 41, 22, define_rect(0, i * 102, 68, 102)));
        sfSprite_setPosition(player->runing[i]->sprite, define_vectorf
        (player->pos.x - player->hb_size.x / 2,
        player->pos.y - player->hb_size.y / 2));
    }
    player->hb_size = define_vectorf(71, 90);
    player->idle = malloc(sizeof(sprite_sheet_t *) * 8);
    for (int i = 0; i < 8; ++i) {
        player->idle[i] = sprite_factory(elements, define_sprite_param
        (skins_idle[skin - 1], 10, 22, define_rect(0, i * 90, 71, 90)));
        sfSprite_setPosition(player->idle[i]->sprite, define_vectorf
        (player->pos.x - player->hb_size.x / 2,
        player->pos.y - player->hb_size.y / 2));
    }
    player->running_clear = sfImage_createFromFile(skins_running[skin - 1]);
    player->idle_clear = sfImage_createFromFile(skins_idle[skin - 1]);
    init_player_two(elements, player, skin);
    return player;
}

void update_texture(elements_t *elements, player_t *player)
{
    char *skins_running[] = {"assets/running.png", "assets/runningred.png",
    "assets/runningblue.png", "assets/runninglgbt.png"};
    char *skins_idle[] = {"assets/idle.png", "assets/idlered.png",
    "assets/idleblue.png", "assets/idlelgbt.png"};

    sfTexture_updateFromImage(get_texture
    (skins_idle[player->skin - 1], elements->tex_list), player->idle_shadow,
    0, 0);
    sfTexture_updateFromImage(get_texture
    (skins_running[player->skin - 1], elements->tex_list),
    player->running_shadow, 0, 0);
}

void refresh_player(elements_t *elements, player_t *player, map_t *map)
{
    int ref_run = -1;

    ((G_U) && !(G_D) && !(G_L) && !(G_R)) ? (ref_run = 0) : (0);
    ((G_U) && !(G_D) && (G_L) && (G_R)) ? (ref_run = 0) : (0);
    ((G_U) && !(G_D) && !(G_L) && (G_R)) ? (ref_run = 1) : (0);
    (!(G_U) && !(G_D) && !(G_L) && (G_R)) ? (ref_run = 2) : (0);
    ((G_U) && (G_D) && !(G_L) && (G_R)) ? (ref_run = 2) : (0);
    (!(G_U) && (G_D) && !(G_L) && (G_R)) ? (ref_run = 3): (0);
    (!(G_U) && (G_D) && !(G_L) && !(G_R)) ? (ref_run = 4): (0);
    (!(G_U) && (G_D) && (G_L) && (G_R)) ? (ref_run = 4) : (0);
    (!(G_U) && (G_D) && (G_L) && !(G_R)) ? (ref_run = 5) : (0);
    (!(G_U) && !(G_D) && (G_L) && !(G_R)) ? (ref_run = 6) : (0);
    ((G_U) && (G_D) && (G_L) && !(G_R)) ? (ref_run = 6) : (0);
    ((G_U) && !(G_D) && (G_L) && !(G_R)) ? (ref_run = 7) : (0);
    (ref_run != -1) ? (player->last_move = ref_run) : (0);
    change_player_visib(player, map);
    update_texture(elements, player);
    (ref_run != -1) ? (refresh_sprite(player->runing[ref_run], elements, 0)) :
    (refresh_sprite(player->idle[player->last_move], elements, 0));
}
