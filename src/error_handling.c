/*
** EPITECH PROJECT, 2019
** Lemin
** File description:
** Error handling
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

char *my_strdup(char const *str)
{
    char *copy = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int i = 0; str[i]; i++)
        copy[i] = str[i];
    copy[my_strlen(str)] = 0;
    return (copy);
}

int check_start_end(save_t **head)
{
    save_t *current = *head;
    int is_start = 0;
    int is_end = 0;

    while (current != NULL) {
        if (my_strcompare(current->str, "##start"))
            is_start = 1;
        if (my_strcompare(current->str, "##end"))
            is_end = 1;
        current = current->next;
    }
    if (is_end == 0 || is_start == 0)
        return (1);
    return (0);
}

int check_room_same_coords(save_t *list)
{
    save_t *rooms = list;
    char *test = NULL;
    char *current_room = NULL;
    char *current_room2 = NULL;
    int i = 0;
    int j = 0;

    for (i = 0, j = 0; list != NULL; list = list->next, j = 0, i = 0) {
        if (list->str[0] != '#' &&
            (test = get_x_coords(my_strdup(list->str))) != NULL) {
            current_room2 = my_strdup(test);
            i = 1;
            rooms = list->next;
        }
        for (; rooms != NULL && i == 1; rooms = rooms->next) {
            if (rooms->str[0] != '#' &&
                (test = get_x_coords(my_strdup(rooms->str))) != NULL) {
                current_room = my_strdup(test);
                j = 1;
            }
            if (my_strcmp(current_room, current_room2) == 0 && j == 1) {
                list->next = NULL;
            }
        }
    }
    return (0);
}

int check_error(save_t **current)
{
    if (check_start_end(current)) {
        my_putstr_error("Fatal error : Start or ending point invalid\n");
        return (84);
    }
    check_room_same_name(current);
    return (0);
}
