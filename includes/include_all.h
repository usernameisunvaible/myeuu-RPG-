/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#ifndef INCLUDE_ALL_H_
    #define INCLUDE_ALL_H_

    #define BLOC_PERCENTIL 5
    #define MAP_SIZE_X 251
    #define MAP_SIZE_Y 251

    #define K_UP sfKeyZ
    #define K_LEFT sfKeyQ
    #define K_DOWN sfKeyS
    #define K_RIGHT sfKeyD
    #define K_CHANGE_UP sfKeyO
    #define K_CHANGE_DOWN sfKeyL
    #define K_TOGGLE_ED sfKeyK
    #define OPEN_B_MENU sfKeyF

#define KEY_CODE elements->event.key.code
    #include "editor.h"
    #include "build_menu.h"
    #include "player.h"
    #include "structures.h"
    #include <stdlib.h>
    #include "belt.h"
    #include "inventory.h"
    #include <SFML/Audio.h>
    #include "hud.h"
    #include "map.h"
    #include "npc.h"
    #include "menu_h.h"
    #include "ennemies.h"

all_belts_t *init_belts(void);
void add_belt(int type, elements_t *elements, belt_t **belt_list,
sfVector2i pos);
void refresh_belts(all_belts_t *belts, elements_t *elements,
sfVector2f player_pos);
void transfere(belt_t *temp, sfVector2i ij, all_belts_t *belts,
elements_t *elements);
void put_item_on_belt(belt_t *temp, int item, elements_t *elements);
void set_item_pos(belt_t *temp, elements_t *elements);
void put_item_on_belt(belt_t *temp, int item, elements_t *elements);
void refresh_player(elements_t *elements, player_t *player, map_t *map);
player_t *init_player(elements_t *elements, player_t *player, int type);
void set_item_pos(belt_t *temp, elements_t *elements);
int refresh_one_belt(belt_t *temp, all_belts_t *belts, sfVector2i ij,
elements_t *elements);
int cond_refresh_item(belt_t *temp, elements_t *elements, sfVector2i ij,
sfVector2f p_pos);
void refresh_counter_belt(all_belts_t *belts);
build_tool_t *init_editor(elements_t *elements);
void refresh_editor(build_tool_t *editor, elements_t *elements,
player_t *player, structures_t *structures);
void del_belt(belt_t *belt);
void refresh_build_menu(elements_t *elements, b_menu_t *b_menu,
player_t *player, sprite_t *sprite);
b_menu_t *init_build_menu(elements_t *elements);
cat_t *init_categorie(elements_t *elements, sfVector2f pos,
void (*func)(cat_t *temp, elements_t *elements, sfVector2f pos));
void refresh_one_cat(elements_t *elements, cat_t *cat, player_t *player,
b_menu_t *b_menu);
void init_belt_cat(cat_t *temp, elements_t *elements, sfVector2f pos);
void button_belt_action(b_menu_t *b_menu, player_t *player,
elements_t *elements);
int build_menu_key(player_t *player, elements_t *elements);
structures_t *init_structures(elements_t *elements);
factory_t *init_factory(elements_t *elements);
all_my_fact_t *init_factories(elements_t *elements);
void refresh_factories(structures_t *structures, elements_t *elements,
sfVector2f p_pos, map_t *map);
void create_fact_one(factory_t *temp, elements_t *elements,
const float bloc_size, char io);
factor_params define_fact_params(int type, char flags);
void refresh_single_fact(structures_t *structures, elements_t *elements,
sfVector2i ij, sfVector2f p_pos);
void refresh_out_fact(structures_t *structures, sfVector2i ij,
elements_t *elements);
void get_item_fact(structures_t *structures, elements_t *elements,
sfVector2i ij);
void receipts_fact(factory_t *fact, elements_t *elements, map_t *map);
void refresh_map(sprite_sheet_t *map, elements_t *elements, player_t *player);
void manage_event_inventory(elements_t *elements, sprite_t *sprite);
void add_inventory(elements_t *elements, sprite_t *sprite);
char *my_itoa(int nb);
void my_life(elements_t *elements, all_t *all);
void my_armor(elements_t *elements, all_t *all);
void my_coins(elements_t *elements, all_t *all);
void inventory_box(elements_t *elements, all_t *all);
void add_hud(elements_t *elements, my_hud_t *hud);
void anim_hp_bar(my_hud_t *hud, all_t *all);
void set_up_var(sprite_t *sprite, all_t *all);
int event(elements_t *elements, sprite_t *sprite, player_t *player,
all_t *all);
void put_belt(build_tool_t *editor, elements_t *elements,
player_t *player, structures_t *structures);
void put_structure(build_tool_t *editor, elements_t *elements,
player_t *player, structures_t *structures);
void init_fact_cat(cat_t *temp, elements_t *elements, sfVector2f pos);
void button_fact_action(b_menu_t *b_menu, player_t *player,
elements_t *elements);
map_t *init_map(elements_t *elements);
sfBool comp_color(sfColor a, sfColor b);
sfVector2f get_pos_on_screen(sfVector2i grid_pos, elements_t *elements,
player_t *player);
void color_colosion(sfImage *colormap, player_t *player, sfVector2f next_pos);
void col_player(player_t *player, structures_t *structures,
elements_t *elements, map_t *map);
factory_t *add_factory(elements_t *elements, structures_t *structures,
sfVector2i pos, int type);
void change_player_visib(player_t *player, map_t *map);
void set_font(all_t *all);
void add_icon(elements_t *elements, sprite_t *sprite);
void event_move_player(elements_t *elements, player_t *player);
void event_move_player2(elements_t *elements, player_t *player);
void event_drag_n_drop_wood(elements_t *elements, sprite_t *sprite,
all_t *all);
void event_drag_n_drop_iron_plate(elements_t *elements, sprite_t *sprite,
all_t *all);
void event_drag_n_drop_copper_plate(elements_t *elements, sprite_t *sprite,
all_t *all);
void event_drag_n_drop_healing_potion(elements_t *elements, sprite_t *sprite,
all_t *all);
void event_drag_n_drop_armor_potion(elements_t *elements, sprite_t *sprite,
all_t *all);
void inventory(elements_t *elements, sprite_t *sprite, all_t *all);
void info_healing(elements_t *elements, all_t *all);
void info_armor_potion(elements_t *elements, all_t *all);
void use_potion(elements_t *elements, sprite_t *sprite, all_t *all);
void set_all_info(elements_t *elements, sprite_t *sprite,
all_t *all);
void info_use_potion(elements_t *elements, all_t *all);
void refresh_npcs(npcl_t *npc, elements_t *elements, player_t *player);
int init_npcs(npcl_t *npc_l, elements_t *elements);
int show_p_menu(pause_m_t *p_m, elements_t *elements, all_t *all);
int init_p_menu(pause_m_t *p_m, elements_t *elements, all_t *all);
aliens_t *init_ennemies(elements_t *elements, int type,
sfVector2i pos_on_grid);
void refresh_alien(elements_t *elements, aliens_t *alien, player_t *player);
void ennemies_attack(all_t *all, player_t *player, aliens_t *alien,
elements_t *elements);
void move_player(elements_t *elements, player_t *player);
void apply_motion(elements_t *elements, aliens_t *alien, player_t *player,
map_t *map);
void delete_potion(elements_t *elements, sprite_t *sprite, all_t *all);
void set_up_music(all_t *all);
void my_hud(elements_t *elements, all_t *all, my_hud_t *hud);
void manage_music(all_t *all);
void add_full(elements_t *elements, sprite_t *sprite, my_hud_t *hud,
all_t *all);

#endif //INCLUDE_ALL_H_
