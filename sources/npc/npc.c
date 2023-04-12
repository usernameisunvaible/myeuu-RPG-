/*
** EPITECH PROJECT, 2021
** npc
** File description:
** npc
*/

#include "../../includes/include_all.h"

char *read_file(char *path)
{
    char *buff;
    int file = open(path, O_RDONLY);
    int size;
    struct stat st;

    stat(path, &st);
    size = st.st_size;
    if (file == -1 || size <= 1)
        return (NULL);
    buff = malloc(sizeof(char) * (size + 1));
    read(file, buff, size);
    buff[size] = '\0';
    close(file);
    return (buff);
}

int get_npc_nb(npcl_t *npc_l, char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            nb++;
    }
    return (nb);
}

int init_single_npc(npcl_t *npc_l, int np, char *str, elements_t *elements)
{
    int i = 0;
    char **dials = my_str_to_word_array(str, '|');

    npc_l->npcs[np].name = dials[0];
    dials++;
    npc_l->npcs[np].dialogs = dials;
    npc_l->npcs[np].sprite = sprite_factory(elements, define_sprite_param
    ("assets/npc.png", 3, 3, define_rect(0, 68, 23, 30)));
    sfSprite_setScale(npc_l->npcs[np].sprite->sprite, (sfVector2f){3, 3});
}

int init_npcs(npcl_t *npc_l, elements_t *elements)
{
    char *str = read_file("assets/npc.txt");
    char **npcs = my_str_to_word_array(str, '\n');
    int np = 0;

    npc_l->nb_npcs = get_npc_nb(npc_l, str);
    npc_l->npcs = malloc(sizeof(npcl_t) * npc_l->nb_npcs);
    for (int i = 0; i < npc_l->nb_npcs; i++) {
        init_single_npc(npc_l, np, npcs[np], elements);
        np++;
    }
}

void refresh_npcs(npcl_t *npc, elements_t *elements, player_t *player)
{
    int pos_x[] = {159, 200};
    int pos_y[] = {70, 170};

    for (int i = 0; i < npc->nb_npcs; i++) {
        sfSprite_setPosition(npc->npcs[i].sprite->sprite, get_pos_on_screen
        (define_vectori(pos_x[i], pos_y[i]), elements, player));
        refresh_sprite(npc->npcs[i].sprite, elements, 0);
    }
}
