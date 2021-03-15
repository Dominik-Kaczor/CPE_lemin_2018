/*
** EPITECH PROJECT, 2019
** Lemin
** File description:
** Help handler
*/

#include "my.h"
#include "prototypes.h"

void print_help(void)
{
    my_putstr("USAGE\n\t./lem_in < [map]\n\nDESCRIPTION\n\t");
    my_putstr("Lem_in is a pathfinder algorithme which can manage severals");
    my_putstr("paths at the same time and have to optimise it for a ");
    my_putstr("precised number of ants\n\t");
    my_putstr("<\ta shell command write the contenant of a file ");
    my_putstr("in the standard inpout\n\t");
    my_putstr("[map]\t path to the file containing informations of the map\n");
}
