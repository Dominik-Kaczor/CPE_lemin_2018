/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** functions used to create the graph based on tunnels.c
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

void create_rooms(save_t **list, rooms_t **other)
{
    rooms_t *ptr = NULL;
    rooms_t *head = NULL;
    int a = 0;

    while ((*list) != NULL && analytics((*list)->str)) {
        if ((*list)->str[0] != '#' && transfo((*list)->str) != NULL) {
            (*other) = malloc(sizeof(rooms_t));
            if (ptr != NULL)
                ptr->next = (*other);
            (*other)->room_name = (*list)->str;
            (*other)->next = NULL;
            if (a == 0)
                head = (*other);
            ptr = (*other);
            (*other) = (*other)->next;
            a++;
        }
        (*list) = (*list)->next;
    }
    (*other) = head;
}

void find_entrance_exit(char **entrance, save_t *ptr, char *str, char **exit)
{
    if (my_strcmp(ptr->str, "##start") == 0)
        *entrance = str;
    if (my_strcmp(ptr->str, "##end") == 0)
        *exit = str;
}

void create_node(save_t **head, int *number_of_tunnel,
                 char **entrance, char **exit)
{
    save_t *parameters = NULL;
    char *str = get_next_line();
    save_t *ptr = NULL;

    while (1) {
        parameters = malloc(sizeof(save_t));
        if (ptr != NULL)
            ptr->next = parameters;
        parameters->str = str;
        *number_of_tunnel += 1;
        if (*head == NULL)
            *head = parameters;
        parameters->next = 0;
        ptr = parameters;
        parameters = parameters->next;
        str = get_next_line();
        if (str == NULL || !my_strcmp(str, "stop_test"))
            return;
        find_entrance_exit(entrance, ptr, str, exit);
    }
}

save_t *create_list(int *number_of_ants, int *number_of_tunnel,
                    char **entrance, char **exit)
{
    char *str = get_next_line();
    save_t *head = NULL;

    if (error_handling(str, number_of_ants) == NULL)
        return (NULL);
    create_node(&head, number_of_tunnel, entrance, exit);
    return (head);
}
