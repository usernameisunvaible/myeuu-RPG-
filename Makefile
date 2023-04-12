##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	engine/sprite.c	\
		engine/sprite_infos.c	\
		engine/textures.c	\
		engine/my_strlen.c	\
		engine/time.c	\
		engine/define_rect.c	\
		engine/init.c	\
		engine/button.c	\
		engine/define_vector.c	\
		engine/button_infos.c	\
		engine/str_comp.c	\
		engine/slide_bar.c	\
		engine/slide_bar_infos.c	\
		engine/text.c	\
		engine/framebuffer.c	\
		engine/drawing.c	\
		engine/define_vertex.c	\
		engine/square.c	\
		engine/text_infos.c	\
		sources/main.c	\
		sources/belt/init_belt.c	\
		sources/belt/belt_transfere.c	\
		sources/belt/refresh_belt.c	\
		sources/belt/item_belts.c	\
		sources/player/init_player.c 	\
		sources/belt/set_item_pos.c	\
		sources/belt/refresh_belt_two.c	\
		sources/editor/editor.c	\
		sources/build_menu/init_build_menu.c	\
		sources/build_menu/init_categories.c	\
		sources/build_menu/belt_cat.c	\
		sources/build_menu/b_menu_key.c	\
		sources/structures/init_structures.c 	\
		sources/structures/init_factories.c 	\
		sources/structures/add_factories.c 	\
		sources/structures/refresh_factory_out.c	\
		sources/structures/refresh_factory.c	\
		sources/structures/refresh_factory_in.c	\
		sources/structures/recipe_fact.c	\
		sources/map/map.c	\
		sources/inventory/init_inventory.c	\
		sources/inventory/event_inventory.c	\
		sources/inventory/write_infos.c	\
		sources/inventory/tools.c		\
		sources/hud/init_hud.c			\
		sources/editor/put_structures.c	\
		sources/build_menu/fact_cat.c	\
		sources/tools/get_pos_on_screen.c	\
		sources/player/collision.c	\
		sources/player/player_shadow.c	\
		sources/player/event_player.c	\
		sources/event/event.c			\
		sources/inventory/event_drag_n_drop.c	\
		sources/inventory/write_infos2.c		\
		sources/inventory/set_info_inventory.c	\
		sources/map/refresh_map.c	\
		sources/npc/my_str_to_word_array.c 	\
		sources/npc/npc.c	\
		sources/npc/dial.c	\
		sources/motion.c 	\
		sources/ennemies/init_ennemies.c	\
		sources/menus/pause_menu.c			\
		sources/inventory/manage_potion.c	\
		sources/main_menu/buttons_handler.c	\
		sources/main_menu/init_menu_assets.c	\
		sources/main_menu/menu.c		\
		sources/main_menu/refresh_assets.c	\
		sources/tools/music.c

OBJ	=	$(SRC:.c=.o)
CFLAGS	+=	-g

NAME	=	my_rpg

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system \
	-lcsfml-audio -lm
	rm $(OBJ)

all:	$(NAME)

clean:
	rm -fr $(OBJ)

fclean:	clean
	rm -fr $(NAME)

re:	fclean all
