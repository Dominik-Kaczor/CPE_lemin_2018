/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** str management tools
*/

#include "my.h"
#include "struct.h"

char *transfo(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (i = 0; str[i] && str[i] != ' '; i++) {
        if (!str[i + 1])
            return (NULL);
    }
    str[i] = 0;
    return (str);
}

int analytics(char *str)
{
    int i = 0;

    if (str[0] == '#')
        return (1);
    for (; str[i] && str[i] != '-'; i++);
    if (str[i] == '-')
        return (0);
    return (1);
}

int nbr_stock(char **stock)
{
    int nb = 0;

    for (int a = 0; stock[a] != NULL; a++)
        nb++;
    return (nb - 1);
}

int nbr_rooms(rooms_t *graph)
{
    int nbr = 0;
    rooms_t *tmp = graph;

    while (tmp != NULL) {
        nbr++;
        tmp = tmp->next;
    }
    return (nbr);
}

int **init_tab(int ants)
{
    int **tmp = malloc(sizeof(int *) * (2));

    for (int j = 0; j != 2; j++)
        tmp[j] = malloc(sizeof(int *) * ants);
    for (int t = 0; t != ants; t++) {
        tmp[0][t] = t + 1;
        tmp[1][t] = 0;
    }
    tmp[1][0] = 1;
    return (tmp);
}
