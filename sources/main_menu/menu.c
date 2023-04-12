/*
** EPITECH PROJECT, 2022
** main_menu
** File description:
** menu
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

menu_t menu(elements_t *elements, menu_t m, all_t *all)
{
    m = button_handler(elements, m, all);
    rf(elements, m);
    return (m);
}
