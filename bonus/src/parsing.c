/*
** EPITECH PROJECT, 2019
** wiewer
** File description:
** functions used to pars the inpud
*/

#include "my.h"
#include "prototypes.h"
#include "struct.h"
#include "gnl.h"

void create_node(save_t **head)
{
    save_t *parameters = NULL;
    char *str = get_next_line();
    save_t *ptr = NULL;

    while (!my_strcompare(str, "#tunnels")) {
        parameters = malloc(sizeof(save_t));
        if (ptr != NULL)
            ptr->next = parameters;
        parameters->str = str;
        if (*head == NULL)
            *head = parameters;
        parameters->next = 0;
        ptr = parameters;
        parameters = parameters->next;
        str = get_next_line();
    }
}

save_t *create_list(void)
{
    save_t *head = NULL;

    create_node(&head);
    return (head);
}

int get_tab_size(save_t *input)
{
    int i = 0;
    save_t *pars = input;

    while (pars != NULL) {
        if (have_space(pars->str) != 84)
            i++;
        pars = pars->next;
    }
    return (i);
}
