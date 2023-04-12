/*
** EPITECH PROJECT, 2022
** B-MUL-200-MLH-2-1-myrpg-david.benistant
** File description:
** buttons_handler
*/

#include "../../engine/includes/include_engine.h"
#include "../../includes/include_all.h"

menu_t skin_buttons(elements_t *elements, menu_t m)
{
    if (m.right_arrow->infos & CLICK_F && m.showcustom < 4) {
        ++m.showcustom;
        elements->left = sfFalse;
        sfSleep(sfSeconds(0.1));
        unclick_b(m.right_arrow);
    }
    if (m.left_arrow->infos & CLICK_F && m.showcustom > 1) {
        --m.showcustom;
        elements->left = sfFalse;
        sfSleep(sfSeconds(0.5));
        unclick_b(m.left_arrow);
    }
    return (m);
}

menu_t button_handler(elements_t *elements, menu_t m, all_t *all)
{
        if (m.play->infos & CLICK_F && m.optvis < 1) {
            all->info.play = 0;
            unclick_b(m.play);
        }
        if (m.opt->infos & CLICK_F) {
            sfSprite_setColor(m.optgui->sprite, sfWhite);
            m.optvis = 2;
            unclick_b(m.opt);
        }
        if (m.quit->infos & CLICK_F && m.optvis < 1)
            sfRenderWindow_close(elements->window);
        if (elements->m_pos.x < 1530 && elements->m_pos.x > 1480) {
            if (elements->m_pos.y < 200 && elements->m_pos.y > 150) {
                m.optvis >= 1 ? sfSprite_setColor(m.optgui->sprite,
                sfTransparent) : 0;
                m.optvis = 0;
            }
        }
        m = skin_buttons(elements, m);
        return (m);
}
