/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../engine/includes/include_engine.h"
#include "../includes/include_all.h"

elements_t *all_textures_paths(void)
{
    char *texture_path_list[] = {"assets/ennemies.png", "assets/belt.png",
    "assets/struct_cat_button.png", "assets/chest_button.png",
    "assets/drill_E_button.png", "assets/stone_furnace_button.png",
    "assets/stone_furnace_preview.png", "assets/chest_preview.png",
    "assets/drill_E_preview.png", "assets/chest.png", "assets/resume.png",
    "assets/quit_menu.png", "assets/back.png", "assets/belts_menu.png",
    "assets/npc.png", "assets/info_box.png", "assets/armor_potion.png",
    "assets/healing_potion.png", "assets/colormap.png", "assets/drill_E.png",
    "assets/wood.png", "assets/inventory_box.png", "assets/defaultskin.png",
    "assets/inventory.png", "assets/belt.png", "assets/box.png",
    "assets/idle.png", "assets/running.png", "assets/map.png",
    "assets/stone_furnace_fire.png", "assets/stone_furnace.png",
    "assets/icon.png", "assets/belt_button/bb_br.png",
    "assets/belt_button/bb_bl.png", "assets/belt_button/bb_lb.png",
    "assets/belt_button/bb_lt.png", "assets/belt_button/bb_tl.png",
    "assets/belt_button/bb_tr.png", "assets/belt_button/bb_rb.png",
    "assets/belt_button/bb_rt.png", "assets/belt_button/bb_tb.png",
    "assets/belt_button/bb_bt.png", "assets/belt_button/bb_rl.png",
    "assets/belt_button/bb_lr.png", "assets/belt_button/prev_belt.png",
    "assets/carre_bleu.png", "assets/box.png", "assets/bgmenu.png",
    "assets/belt_preview.png", "assets/optgui.png", "assets/option.png",
    "assets/quit.png", "assets/lgbtskin.png", "assets/play.png",
    "assets/blueskin.png", "assets/redskin.png", "assets/leftarrow.png",
    "assets/rightarrow.png", "assets/runningred.png", "assets/runningblue.png",
    "assets/runninglgbt.png", "assets/idlered.png", "assets/idleblue.png",
    "assets/idlelgbt.png", "\0"};
    char *font_path_list[] = {"\0"};
    return init_elements(texture_path_list, font_path_list);
}

void move_p(player_t *player, int x, int y)
{
    player->pos.x += x;
    player->pos.y += y;
}

void move_player(elements_t *elements, player_t *player)
{
    player->timer_tot += elements->chrono->ms - player->timer;
    while (player->timer_tot >= 16) {
        ((G_U) && !(G_D) && !(G_L) && !(G_R)) ? (player->pos.y -= P_SP) : (0);
        ((G_U) && !(G_D) && (G_L) && (G_R)) ? (player->pos.y -= P_SP) : (0);
        ((G_U) && !(G_D) && !(G_L) && (G_R)) ?
        (move_p(player, P_SP_DI, -P_SP_DI)) : (0);
        (!(G_U) && !(G_D) && !(G_L) && (G_R)) ? (player->pos.x += P_SP) : (0);
        ((G_U) && (G_D) && !(G_L) && (G_R)) ? (player->pos.x += P_SP) : (0);
        (!(G_U) && (G_D) && !(G_L) && (G_R)) ?
        (move_p(player, P_SP_DI, P_SP_DI)): (0);
        (!(G_U) && (G_D) && !(G_L) && !(G_R)) ? (player->pos.y += P_SP): (0);
        (!(G_U) && (G_D) && (G_L) && (G_R)) ? (player->pos.y += P_SP) : (0);
        (!(G_U) && (G_D) && (G_L) && !(G_R)) ?
        (move_p(player, -P_SP_DI, P_SP_DI)) : (0);
        (!(G_U) && !(G_D) && (G_L) && !(G_R)) ? (player->pos.x -= P_SP) : (0);
        ((G_U) && (G_D) && (G_L) && !(G_R)) ? (player->pos.x -= P_SP) : (0);
        ((G_U) && !(G_D) && (G_L) && !(G_R)) ?
        (move_p(player, -P_SP_DI, -P_SP_DI)) : (0);
        player->timer_tot -= 16;
    }
    player->timer = elements->chrono->ms;
}

void my_loop(elements_t *elements, all_t *all, pause_m_t p_m, player_t *player)
{
    map_t *map = init_map(elements);
    structures_t *structures = init_structures(elements);
    aliens_t *alien = init_ennemies(elements, 1, define_vectori(150, 75));
    sprite_t *sprite = malloc(sizeof(sprite_t) + 1);
    my_hud_t *hud = malloc(sizeof(my_hud_t));
    menu_t m = init_menu_elems(m, elements);
    npcl_t npc_l;

    add_full(elements, sprite, hud, all);
    init_npcs(&npc_l, elements);
    init_dials(&npc_l, elements, all);
    while (sfRenderWindow_isOpen(elements->window)) {
        if (all->info.play == 1)
            m = menu(elements, m, all);
        else {
            (player->first_time) ? (player = init_player(elements, player,
            m.showcustom)) : (0);
            col_player(player, structures, elements, map);
            apply_motion(elements, alien, player, map);
            refresh_map(map->map, elements, player);
            refresh_alien(elements, alien, player);
            ennemies_attack(all, player, alien, elements);
            refresh_belts(structures->belts, elements, player->pos);
            refresh_factories(structures, elements, player->pos, map);
            refresh_editor(player->editor, elements, player, structures);
            refresh_npcs(&npc_l, elements, player);
            refresh_player(elements, player, map);
            npc_prox(&npc_l, elements, all);
            refresh_build_menu(elements, player->b_menu, player, sprite);
            event(elements, sprite, player, all);
            my_hud(elements, all, hud);
            show_p_menu(&p_m, elements, all);
            refresh_elements(elements);
            sfRenderWindow_clear(elements->window, sfBlack);
        }
    }
}

int main(int ac, char **av)
{
    elements_t *elements = all_textures_paths();
    all_belts_t *belts = init_belts();
    all_t *all = malloc(sizeof(all_t));
    const float bloc_size = (elements->win_size.y * BLOC_PERCENTIL / 100);
    pause_m_t p_m;
    player_t *player = malloc(sizeof(player_t));
    player->first_time = sfTrue;

    init_p_menu(&p_m, elements, all);
    my_loop(elements, all, p_m, player);
    close_elements(elements);
    return 0;
}
