/*
** EPITECH PROJECT, 2018
** Matchstick
** File description:
** Reproduce the matchstick game
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main_test(void);

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_redirect_stdin();
}

static void redirect(void)
{
    cr_redirect_stdin();
}

Test(lemin, anthill, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/map_solved/anthill", "r");
    fprintf(cr_get_redirected_stdin(), "%s", "3\n##start\n0 1 0\n##end\n1 13 0 #bedroom\n2 5 0\n# The next room is the kitchen\n3 9 0\n0-2\n2-3\n3-1\nstop_test\n");
    main_test();
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(lemin, input, .init = redirect_all_std)
{
    FILE *solved = fopen("tests/map_solved/input", "r");
    fprintf(cr_get_redirected_stdin(), "%s", "34\n##start\n1 23 3\n2 16 7\n#comment\n3 16 3\n4 16 5\n5 9 3\n6 1 0\n7 4 8\n##end\n0 9 5\n0-4\n0-6\n1-3\n4-3\n5-2\n3-5\n#another comment\n4-2\n2-1\n7-6\n7-2\n7-4\n6-5\nstop_test\n");
    main_test();
    cr_assert_stdout_eq(solved);
    fclose(solved);
}
