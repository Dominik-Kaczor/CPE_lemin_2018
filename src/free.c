/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** function for free allocated portions
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

char *error_handling(char *str, int *number_of_ants)
{
    if (str != NULL && my_str_isnum(str))
        *number_of_ants = my_getnbr(str);
    if (*number_of_ants <= 0)
        return (NULL);
    free(str);
    return ("a");
}

void free_map(rooms_t *head, save_t *list)
{
    rooms_t *ptr = head;
    save_t *node = list;

    while (head != NULL) {
        ptr = head->next;
        free(head->tunnels);
        free(head->room_name);
        free(head);
        head = ptr;
    }
    while (list != NULL) {
        node = list->next;
        free(list->str);
        free(list);
        list = node;
    }
}

void free_all(char *t1, char *t2)
{
    if (t1 != NULL)
        free(t1);
    if (t2 != NULL)
        free(t2);
}
