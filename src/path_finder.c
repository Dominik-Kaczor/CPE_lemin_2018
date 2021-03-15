/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** all functions used by the path_finder
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

void path_finder(int space, int **war, int ants, char **stock)
{
    for (int h = 0; h != ants; h++) {
        if (war[1][h] != 0 && war[1][h] != -1) {
            if (space == 1)
                my_printf(" ");
            my_printf("P%d-%s", war[0][h], stock[war[1][h]]);
            space = 1;
        }
    }
}

int path_finder_others_paths(int ants, int **war, int rooms, int but)
{
    for (int h = 0; h != ants; h++) {
        if (war[1][h] == rooms) {
            war[1][h] = -1;
            but++;
        }
        if (war[1][h] == -1) {
        } else if (h == 0 && war[1][h] != -1) {
            war[1][0] = war[1][0] + 1;
        } else if (war[1][h - 1] == -1 || war[1][h - 1] > war[1][h] + 1)
            war[1][h] = war[1][h] + 1;
    }
    return (but);
}

char **other_path(rooms_t *graph, char **stock)
{
    static int q = 0;
    rooms_t *save = graph;

    if (save->tunnels[q]->room_name == stock[1]) {
        if (save->tunnels[q + 1] != NULL)
            stock[1] = save->tunnels[q + 1]->room_name;
        else {
            stock[0] = NULL;
            return (stock);
        }
            }
    q++;
    for (int e = 2; stock[e] != NULL; e++)
        stock[e] = NULL;
    return (stock);
}

char *check_last(char **stock)
{
    char *str = NULL;

    for (int y = 0; stock[y]; y++) {
        if (stock[y + 1] == NULL) {
            str = stock[y];
            break;
        }
    }
    return (str);
}
