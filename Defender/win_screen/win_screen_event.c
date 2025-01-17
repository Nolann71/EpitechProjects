/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** check event for win screen
*/

#include "include/defender.h"

void check_win_screen_event(game_t *main_s)
{
    sfEvent et = main_s->event;
    const sfView *view = sfRenderWindow_getView(main_s->win);
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(main_s->win);
    sfVector2f pos_mouse;

    pos_mouse = sfRenderWindow_mapPixelToCoords(main_s->win, p_mouse, view);
    while (sfRenderWindow_pollEvent(main_s->win, &et)) {
        if (et.type == sfEvtClosed)
            sfRenderWindow_close(main_s->win);
        check_win_screen_hover(main_s, pos_mouse);
        if (et.type == sfEvtMouseButtonPressed && et.type != sfEvtClosed) {
            p_mouse.x = et.mouseButton.x;
            p_mouse.y = et.mouseButton.y;
            pos_mouse = sfRenderWindow_mapPixelToCoords(main_s->win,
            p_mouse, view);
            check_win_screen_clic(main_s, pos_mouse);
        }
        else
            win_screen_check_button_none(main_s);
    }
}