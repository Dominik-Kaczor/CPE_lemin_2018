/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** display needs for lem_in before the #moves
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

char *manage_str(char *str)
{
    if (str[0] == '#')
        return (str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#') {
            str[i] = '\0';
            return (str);
        }
    }
    return (str);
}

int str_banned(char *str, char a, char b)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == a || str[i] == b)
            return (84);
    }
    return (0);
}

int get_tunnels(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            return (0);
    }
    return (84);
}

void display_tunnels(save_t *list)
{
    save_t *tmp = list;

    while (tmp != NULL) {
        if (get_tunnels(tmp->str) == 0)
            my_printf("%s\n", manage_str(tmp->str));
        tmp = tmp->next;
    }
}

void display_base(save_t *current, save_t *list, int nb_ants)
{
    my_printf("#number_of_ants\n%d\n", nb_ants);
    my_printf("#rooms\n");
    find_rooms(current);
    my_printf("##start\n%s\n", manage_str(find_start(current)));
    my_printf("##end\n%s\n", manage_str(find_end(current)));
    find_other_rooms(current);
    my_printf("#tunnels\n");
    display_tunnels(list);
    my_printf("#moves\n");
}
