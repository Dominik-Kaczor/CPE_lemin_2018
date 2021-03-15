/*
** EPITECH PROJECT, 2019
** Tests generic
** File description:
** This set of tests test the program function by function
*/

#include "my.h"
#include "struct.h"
#include "prototypes.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(manage_str, modify_str)
{
    char *str = "##start";
    char *dest = manage_str(str);

    cr_assert_str_eq(dest, str);
}

Test(manage_str, valid_modify)
{
    char *str = "1 13 4";
    char *dest = manage_str(str);

    cr_assert_str_eq(dest, "1 13 4");
}

Test(str_banned, invalid)
{
    char *str = "salut";
    int dest = str_banned(str, 'a', 'b');

    cr_assert_eq(dest, 84);
}

Test(str_banned, valid)
{
    char *str = "salut";
    int dest = str_banned(str, 'c', 'b');

    cr_assert_eq(dest, 0);
}

Test(get_tunnels, valid)
{
    char *str = "7-8";
    int dest = get_tunnels(str);

    cr_assert_eq(dest, 0);
}

Test(get_tunnels, invalid)
{
    char *str = "7z8";
    int dest = get_tunnels(str);

    cr_assert_eq(dest, 84);
}

Test(my_strdup, valid)
{
    char *str = "salut";
    char *dest = my_strdup(str);

    cr_assert_str_eq(dest, "salut");
}

Test(check_is_not_room, first_is_room)
{
    char *str1 = "3-7";
    char *str2 = "4-3";

    int dest = check_is_not_room(str1, str2);
    cr_assert_eq(dest, 1);
}

Test(check_is_not_room, is_not_room)
{
    char *str1 = "tien";
    char *str2 = "salut";

    int dest = check_is_not_room(str1, str2);
    cr_assert_eq(dest, 0);
}

Test(check_is_not_room, second_is_room)
{
    char *str1 = "tien";
    char *str2 = "3-7";

    int dest = check_is_not_room(str1, str2);
    cr_assert_eq(dest, 1);
}

Test(check_is_not_room_single, is_not_room)
{
    char *str1 = "tien";

    int dest = check_is_not_room_single(str1);
    cr_assert_eq(dest, 0);
}

Test(check_is_not_room_single, is_room)
{
    char *str1 = "8-4";

    int dest = check_is_not_room_single(str1);
    cr_assert_eq(dest, 1);
}

Test(my_compare_room, same)
{
    char *str1 = "8-4";
    char *str2 = "8-4";

    int dest = my_compare_room(str1, str2);
    cr_assert_eq(dest, 0);
}

Test(my_compare_room, different)
{
    char *str1 = "8-4";
    char *str2 = "z";

    int dest = my_compare_room(str1, str2);
    cr_assert_eq(dest, 0);
}

Test(get_x_coords, invalid)
{
    char *str = "salut";
    char *dest = get_x_coords(str);

    cr_assert_str_eq(dest, "\0");
}

Test(find_start, valid)
{
    save_t *list = malloc(sizeof(save_t));
    char *dest;

    list->str = "3";
    list->next = malloc(sizeof(save_t));
    list->next->str = "##start";
    list->next->next = malloc(sizeof(save_t));
    list->next->next->str = "#tkt";
    list->next->next->next = malloc(sizeof(save_t));
    list->next->next->next->str = "1 13 1";
    dest = find_start(list);
    cr_assert_str_eq(dest, "1 13 1");
}

Test(find_end, valid)
{
    save_t *list = malloc(sizeof(save_t));
    char *dest;

    list->str = "3";
    list->next = malloc(sizeof(save_t));
    list->next->str = "##end";
    list->next->next = malloc(sizeof(save_t));
    list->next->next->str = "#tkt";
    list->next->next->next = malloc(sizeof(save_t));
    list->next->next->next->str = "1 13 1";
    dest = find_end(list);
    cr_assert_str_eq(dest, "1 13 1");
}

Test(find_rooms, valid, .init = redirect_all_std)
{
    save_t *list = malloc(sizeof(save_t));

    list->str = "1 13 2";
    list->next = malloc(sizeof(save_t));
    list->next->str = "1 4 3";
    list->next->next = malloc(sizeof(save_t));
    list->next->next->str = "#tkt";
    list->next->next->next = malloc(sizeof(save_t));
    list->next->next->next->str = "##start";
    find_rooms(list);
    cr_assert_stdout_eq_str("1 13 2\n1 4 3\n#tkt\n");
}

Test(print_help, valid, .init = redirect_all_std)
{
    print_help();

    cr_assert_stdout_eq_str("USAGE\n\t./lem_in < [map]\n\nDESCRIPTION\n\tLem_in is a pathfinder algorithme which can manage severalspaths at the same time and have to optimise it for a precised number of ants\n\t<\ta shell command write the contenant of a file in the standard inpout\n\t[map]\t path to the file containing informations of the map\n");
}

Test(analytics, invalid)
{
    char *str = "salut";
    int dest = analytics(str);

    cr_assert_eq(dest, 1);
}

Test(analytics, valid)
{
    char *str = "##start";
    int dest = analytics(str);

    cr_assert_eq(dest, 1);
}

Test(analytics, second_valid)
{
    char *str = "5-5";
    int dest = analytics(str);

    cr_assert_eq(dest, 0);
}
