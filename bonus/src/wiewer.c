/*
** EPITECH PROJECT, 2019
** wiewer.c
** File description:
** all functions used to dislpay the wiewer programm
*/

#include "my.h"
#include "prototypes.h"
#include "struct.h"
#include "gnl.h"

void wiewer(button_t **buttons)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 34};
    sfEvent event;

    window = sfRenderWindow_create(video_mode, "My Window", sfResize |
                                   sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 80);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_rooms(buttons, window);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
    }
}
