/*
** EPITECH PROJECT, 2019
** algo
** File description:
** astra
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

void display_mov(int ants, char **stock)
{
    int **war = init_tab(ants);
    int but = 0;
    int space = 0;
    int rooms = nbr_stock(stock);

    while (but != ants) {
        path_finder(space, war, ants, stock);
        space = 0;
        but = path_finder_others_paths(ants, war, rooms, but);
        my_printf("\n");
    }
}

char *verification(rooms_t *save, char **stock)
{
    char *str = NULL;
    int k = 0;

    for (int b = 0;stock[b] != NULL; b++) {
        if (save->tunnels[k] == NULL)
            return ("-1");
        if (my_strcmp(save->tunnels[k]->room_name, stock[b]) != 0)
            str = save->tunnels[k]->room_name;
        for (int m = 0; stock[m] != NULL; m++) {
            if (my_strcmp(stock[m], str) == 0) {
                k++;
                b = 0;
            }
        }
    }
    if (str == NULL)
        return("-1");
    return (str);
}

char **pathfinding_b(char **stock, rooms_t **save, rooms_t *graph)
{
    static int d = 0;
    static char *str = NULL;

    if (str == NULL && d == 0)
        str = (*save)->room_name;
    if (my_strcmp(str, (*save)->room_name) == 0) {
        str = verification((*save), stock);
        if (my_strcmp(str, "-1") == 0) {
            stock = other_path(graph, stock);
            str = check_last(stock);
            d = 1;
            (*save) = graph;
        } else {
            d++;
            stock[d] = str;
            (*save) = graph;
        }
    }
    return (stock);
}

char **pathfinding(char **stock, rooms_t *graph, char *exit)
{
    rooms_t *save = graph;

    while (1) {
        if (my_strcmp(save->room_name, exit) == 0)
            break;
        stock = pathfinding_b(stock, &save, graph);
        if (stock[0] == NULL)
            return (stock);
        save = save->next;
    }
    return (stock);
}

void algo(rooms_t *graph, char *exit, int ants)
{
    rooms_t *save = graph;
    char **stock = malloc(sizeof(char*) * (nbr_rooms(graph) + 1));

    for (int o = 0; o != nbr_rooms(graph) + 1; o++)
        stock[o] = NULL;
    stock[0] = save->room_name;
    stock = pathfinding(stock, graph, exit);
    if (stock[0] == NULL)
        return;
    display_mov(ants, stock);
}
