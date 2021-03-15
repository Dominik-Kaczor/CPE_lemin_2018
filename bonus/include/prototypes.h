/*
** EPITECH PROJECT, 2018
** Lemin
** File description:
** Header file
*/

#include "struct.h"

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

save_t *create_list(void);
int get_tab_size(save_t *input);
void init(button_t **button, save_t *input);
void wiewer(button_t **buttons);
int take_second_nb(char *str);
int take_third_nb(char *str);
int have_space(char *str);
void display_rooms(button_t **button, sfRenderWindow *window);
char *get_next_line(void);

#endif
