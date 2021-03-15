/*
** EPITECH PROJECT, 2019
** assign_tunnel
** File description:
** osef
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

void separate(char *str, char **t1, char **t2)
{
    int inc = 0;
    int i = 0;

    *t1 = malloc(sizeof(char) * my_strlen(str) + 1);
    *t2 = malloc(sizeof(char) * my_strlen(str) + 1);
    for (i = 0; str[inc] && str[inc] != '-'; i++)
        (*t1)[i] = str[inc++];
    (*t1)[i] = 0;
    inc++;
    for (i = 0; str[inc]; i++)
        (*t2)[i] = str[inc++];
    (*t2)[i] = 0;
}

void assign_name(rooms_t *head, rooms_t **other, save_t *list, int *i)
{
    rooms_t *assign = head;
    char *t1 = NULL;
    char *t2 = NULL;

    separate(list->str, &t1, &t2);
    if (my_strcmp((*other)->room_name, t1) == 0) {
        while (my_strcmp(assign->room_name, t2) != 0 && assign != NULL)
            assign = assign->next;
        (*other)->tunnels[*i] = assign;
        *i += 1;
    } else if (my_strcmp((*other)->room_name, t2) == 0) {
        while (my_strcmp(assign->room_name, t1) != 0 && assign != NULL)
            assign = assign->next;
        (*other)->tunnels[*i] = assign;
        *i += 1;
    }
    free_all(t1, t2);
}

void ant_handler(rooms_t **other, save_t *list, save_t *tunnels_head,
                 int *tunel_per_room)
{
    rooms_t *head = (*other);
    int i = 0;

    for (int m = 0; (*other) != NULL; m++, i = 0) {
        (*other)->tunnels = malloc(sizeof(rooms_t*) * (tunel_per_room[m] + 1));
        tunnels_head = list;
        while (tunnels_head != NULL) {
            assign_name(head, other, tunnels_head, &i);
            tunnels_head = tunnels_head->next;
        }
        (*other)->tunnels[tunel_per_room[m]] = NULL;
        (*other) = (*other)->next;
    }
    (*other) = head;
}

void count_tunnels_per_room(int **tunnel_per_room, save_t *tunnels_head,
                            rooms_t **other, int i)
{
    rooms_t *head = (*other);
    char *t1;
    char *t2;

    (*tunnel_per_room) = malloc(sizeof(int) * i);
    for (int m = 0; m < i; m++)
        (*tunnel_per_room)[m] = 0;
    while (tunnels_head != NULL) {
        separate(tunnels_head->str, &t1, &t2);
        (*other) = head;
        for (int m = 0; (*other) != NULL; m++) {
            if (my_strcmp((*other)->room_name, t1) == 0 ||
                my_strcmp((*other)->room_name, t2) == 0) {
                (*tunnel_per_room)[m] += 1;
            }
            (*other) = (*other)->next;
        }
        free_all(t1, t2);
        tunnels_head = tunnels_head->next;
    }
}

int assign_tunnel(rooms_t **other, save_t *list)
{
    save_t *tunnels_head = list;
    rooms_t *head = (*other);
    int *tunnel_per_room;
    int i = 0;

    for (i = 0; (*other) != NULL; i++)
        (*other) = (*other)->next;
    (*other) = head;
    count_tunnels_per_room(&tunnel_per_room, tunnels_head, other, i);
    (*other) = head;
    ant_handler(other, list, tunnels_head, tunnel_per_room);
    free(tunnel_per_room);
    return (0);
}
