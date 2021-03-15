/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** all functions used to find informations on the inpout
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

char *find_start(save_t *current)
{
    save_t *tmp = current;

    while (!my_strcompare(tmp->str, "##start")) {
        tmp = tmp->next;
    }
    while (tmp->str[0] == '#')
        tmp = tmp->next;
    return (tmp->str);
}

char *find_end(save_t *current)
{
    save_t *tmp = current;

    while (!my_strcompare(tmp->str, "##end")) {
        tmp = tmp->next;
    }
    while (tmp->str[0] == '#')
        tmp = tmp->next;
    return (tmp->str);
}

void find_rooms(save_t *current)
{
    save_t *tmp = current;

    while (!(my_strcompare(tmp->str, "##start")) || tmp->str[0] != '#') {
        my_printf("%s\n", manage_str(tmp->str));
        tmp = tmp->next;
    }
}

void display_other_rooms(save_t *current, save_t **save, int max)
{
    int i = 0;
    int k = 0;

    while (i != max) {
        if (my_strcompare(save[i]->str, manage_str(find_start(current))))
            k = i;
        i++;
    }
    k++;
    while (k != max) {
        if (!my_strcompare(save[k]->str, manage_str(find_end(current))))
            my_printf("%s\n", save[k]->str);
        k++;
    }
}

void find_other_rooms(save_t *current)
{
    save_t *tmp = current;
    save_t *rooms = current;
    save_t **save;
    int i = 0;
    int k = 0;

    while (tmp != NULL) {
        if (str_banned(manage_str(tmp->str), '#', '-') == 0)
            i++;
        tmp = tmp->next;
    }
    save = malloc(sizeof(save_t *) * i);
    for (int j = 0; rooms != NULL; j++) {
        if (str_banned(manage_str(rooms->str), '#', '-') == 0) {
            save[k] = rooms;
            k++;
        }
        rooms = rooms->next;
    }
    display_other_rooms(current, save, i);
}
