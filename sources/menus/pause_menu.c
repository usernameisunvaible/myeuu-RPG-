/*
** EPITECH PROJECT, 2021
** npc
** File description:
** npc
*/

#include "../../includes/include_all.h"

int init_p_menu(pause_m_t *p_m, elements_t *elements, all_t *all)
{
    p_m->last_time = 0;
    p_m->resume = init_button(elements,
    define_button_params("assets/resume.png",
    define_rect(690, 400, 606, 99), 1, 10));
    p_m->quit = init_button(elements,
    define_button_params("assets/quit_menu.png",
    define_rect(690, 640, 606, 99), 1, 5));
    p_m->back = init_button(elements,
    define_button_params("assets/back.png",
    define_rect(690, 520, 606, 99), 1, 10));
    p_m->menu = sfSprite_create();
    sfSprite_setTexture(p_m->menu, sfTexture_createFromFile(\
    "assets/pause_menu.png", NULL), sfFalse);
}

int draw_menu(pause_m_t *p_m, elements_t *elements, all_t *all)
{
    sfRenderWindow_setMouseCursorVisible(elements->window, sfTrue);
    sfRenderWindow_drawSprite(elements->window, p_m->menu, NULL);
    show_b(p_m->resume);
    show_b(p_m->quit);
    show_b(p_m->back);
    show_button(p_m->resume, elements);
    show_button(p_m->quit, elements);
    show_button(p_m->back, elements);
    if (p_m->quit->infos & CLICK_F) {
        sfRenderWindow_close(elements->window);
    }
    if (p_m->resume->infos & CLICK_F) {
        p_m->open = 0;
        unclick_b(p_m->resume);
    }
    if (p_m->back->infos & CLICK_F) {
        all->info.play = 1;
        unclick_b(p_m->back);
    }
}

int show_p_menu(pause_m_t *p_m, elements_t *elements, all_t *all)
{
    long actual = sfClock_getElapsedTime(elements->chrono->clock).microseconds;

    elements->is_on_p_menu = 0;
    if (p_m->open && p_m->open != 1)
        p_m->open = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
    actual - p_m->last_time > 400000) {
        p_m->last_time = sfClock_getElapsedTime(\
    elements->chrono->clock).microseconds;
        p_m->open = (p_m->open == 1 ? 0 : 1);
    }
    if (p_m->open == 1) {
        elements->is_on_p_menu = 1;
        draw_menu(p_m, elements, all);
    } else {
        hide_b(p_m->resume);
        hide_b(p_m->quit);
        hide_b(p_m->back);
    }
}
