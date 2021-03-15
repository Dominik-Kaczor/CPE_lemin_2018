/*
** EPITECH PROJECT, 2019
** wiewer
** File description:
** main.c
*/

#include "my.h"
#include "prototypes.h"
#include "struct.h"
#include "gnl.h"

int main(void)
{
    save_t *input = create_list();
    int i = get_tab_size(input);
    button_t **button = malloc(sizeof(button_t *) * i);

    init(button, input);
    wiewer(button);
    return (0);
}
