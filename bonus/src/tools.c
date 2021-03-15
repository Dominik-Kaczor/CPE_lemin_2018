/*
** EPITECH PROJECT, 2019
** wiewe
** File description:
** all little functions used on wiewer
*/

#include "my.h"
#include "prototypes.h"
#include "struct.h"
#include "gnl.h"

int have_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            return (0);
    }
    return (84);
}

char *my_strdup(char const *str)
{
    char *copy = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int i = 0; str[i]; i++)
        copy[i] = str[i];
    copy[my_strlen(str)] = 0;
    return (copy);
}

int take_second_nb(char *str)
{
    char *tmp = my_strdup(str);
    int i = 0;

    while (tmp[i] != ' ') {
        tmp++;
    }
    tmp++;
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] == ' ')
            tmp[i] = '\0';
    }
    return (my_getnbr(tmp));
}

int take_third_nb(char *str)
{
    char *tmp = my_strdup(str);

    for (int i = 0; tmp[i] != ' '; tmp++);
    tmp++;
    for (int i = 0; tmp[i] != ' '; tmp++);

    return (my_getnbr(tmp));
}
