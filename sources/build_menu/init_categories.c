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

cat_t *init_categorie(elements_t *elements, sfVector2f pos,
void (*func)(cat_t *temp, elements_t *elements, sfVector2f pos))
{
    cat_t *temp = malloc(sizeof(cat_t));

    temp->is_active = sfFalse;
    (*func)(temp, elements, pos);
    return temp;
}

void refresh_one_cat(elements_t *elements, cat_t *cat, player_t *player,
b_menu_t *b_menu)
{
    show_button(cat->cat_button, elements);
    if (cat->is_active) {
        for (int i = 0; i < cat->nb_obj; ++i)
            show_button(cat->obj_prev[i], elements);
        button_belt_action(b_menu, player, elements);
        button_fact_action(b_menu, player, elements);
    }
}
