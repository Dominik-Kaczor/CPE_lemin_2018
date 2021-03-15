/*
** EPITECH PROJECT, 2019
** Lemin
** File description:
** Main
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

int main_test(void)
{
    int number_of_ants = 0;
    int number_of_tunnel = 0;
    char *entrance = NULL;
    char *exit = NULL;
    save_t *list = create_list(&number_of_ants, &number_of_tunnel,
                               &entrance, &exit);
    save_t *current = list;
    rooms_t *other = NULL;
    rooms_t *head = NULL;

    if (check_error(&list) == 84)
        return (84);
    display_base(current, list, number_of_ants);
    create_rooms(&list, &other);
    head = other;
    assign_tunnel(&head, list);
    sort(&head, entrance, exit);
    algo(head, exit, number_of_ants);
    free_map(head, list);
    return (0);
}
