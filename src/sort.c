/*
** EPITECH PROJECT, 2019
** Lemin
** File description:
** Main
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"

void head_it(rooms_t **other, char *entrance, rooms_t **last, rooms_t **head)
{
    rooms_t *ptr = *other;

    while (*other != NULL) {
        if (my_strcmp((*other)->room_name, entrance) == 0 &&
            my_strcmp((*other)->room_name, (*head)->room_name)) {
            ptr->next = (*other)->next;
            (*other)->next = *head;
            *head = (*other);
            (*other) = ptr;
        }
        ptr = *other;
        if ((*other)->next == NULL)
            (*last) = (*other);
        (*other) = (*other)->next;
    }
}

void tail_it(rooms_t **other, char *exit, rooms_t *last)
{
    rooms_t *ptr = *other;

    while (*other != NULL) {
        if (my_strcmp((*other)->room_name, exit) == 0 &&
            my_strcmp((*other)->room_name, last->room_name) != 0) {
            ptr->next = (*other)->next;
            last->next = (*other);
            (*other)->next = NULL;
            break;
        }
        ptr = *other;
        (*other) = (*other)->next;
    }
}

void sort(rooms_t **other, char *entrance, char *exi)
{
    rooms_t *head = *other;
    rooms_t *last = *other;

    head_it(other, entrance, &last, &head);
    (*other) = head;
    tail_it(other, exi, last);
    (*other) = head;
}
