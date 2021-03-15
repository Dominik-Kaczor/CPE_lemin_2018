/*
** EPITECH PROJECT, 2019
** wiewer.c
** File description:
** functions used to display and create buttons
*/

#include "my.h"
#include "prototypes.h"
#include "struct.h"
#include "gnl.h"

button_t *fill_button(char *str)
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->y = take_third_nb(str);
    button->x = take_second_nb(str);
    button->texture = sfTexture_createFromFile("bonus/sprites/roms.png", NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    button->size.x = 50;
    button->size.y = 50;
    button->pos.x = button->x * 1920 / 30;
    button->pos.y = button->y * 1080 / 15;
    return (button);
}

void init(button_t **button, save_t *input)
{
    save_t *tmp = input;
    int i = 0;

    while (tmp != NULL) {
        if (have_space(tmp->str) != 84) {
            button[i] = fill_button(tmp->str);
            i++;
        }
        tmp = tmp->next;
    }
}

void display_rooms(button_t **button, sfRenderWindow *window)
{
    int n = 0;

    while (button[n] != NULL) {
        sfRectangleShape_setPosition(button[n]->rect, button[n]->pos);
        sfRectangleShape_setSize(button[n]->rect, button[n]->size);
        sfRenderWindow_drawRectangleShape(window, button[n]->rect, NULL);
        n++;
    }
}
