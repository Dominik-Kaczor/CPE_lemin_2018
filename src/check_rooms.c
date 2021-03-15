/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** functions which informations about the input
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

char *get_x_coords(char *str)
{
    int i = 0;

    if (check_is_not_room_single(str))
        return (NULL);
    while (*str != '\0') {
        if (*str++ == ' ')
            break;
    }
    while (str[i] != '\0') {
        if (str[i] == ' ')
            str[i] = '\0';
        i++;
    }
    return (str);
}

int check_is_not_room_single(char *first)
{
    for (int i = 0; first[i]; i++)
        if (first[i] == '-')
            return (1);
    return (0);
}

int check_is_not_room(char *first, char *second)
{
    for (int i = 0; first[i]; i++) {
        if (first[i] == '-')
            return (1);
    }
    for (int i = 0; second[i]; i++) {
        if (second[i] == '-')
            return (1);
    }
    return (0);
}

int my_compare_room(char *first, char *second)
{
    int i = 0;

    if (check_is_not_room(first, second))
        return (0);
    for (i = 0; first[i] != '\0' && first[i]!= ' '; i++);
    first[i] = '\0';
    for (i = 0; second[i] != '\0' && second[i]!= ' '; i++);
    second[i] = '\0';
    if (my_strcompare(first, second))
        return (1);
    return (0);
}

int check_room_same_name(save_t **head)
{
    save_t *rooms = *head;
    save_t *list = *head;
    char *to_compare = NULL;

    while (list != NULL) {
        to_compare = my_strdup(list->str);
        rooms = list->next;
        while (rooms != NULL && to_compare[0] != '#') {
            if (rooms->str[0] != '#')
                if (my_compare_room(my_strdup(rooms->str), to_compare)) {
                    return (1);
                }
            rooms = rooms->next;
        }
        list = list->next;
    }
    return (0);
}
