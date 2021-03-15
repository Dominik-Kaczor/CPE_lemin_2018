/*
** EPITECH PROJECT, 2018
** Lemin
** File description:
** Header file
*/

#include "struct.h"

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

void create_rooms(save_t **list, rooms_t **other);
save_t *create_list(int *number_of_ants, int *number_of_tunnel,
                    char **entrance, char **exit);
int check_room_same_name(save_t **list);
int **init_tab(int ants);
int nbr_rooms(rooms_t *graph);
int path_finder_others_paths(int ants, int **war, int rooms, int but);
void path_finder(int space, int **war, int ants, char **stock);
char *my_strdup(char const *str);
int check_start_end(save_t **current);
int check_is_not_room(char *first, char *second);
int check_is_not_room_single(char *first);
int my_compare_room(char *first, char *second);
char *get_x_coords(char *str);
void display_tunnels(save_t *list);
int nbr_stock(char **stock);
int get_tunnels(char *str);
char *manage_str(char *str);
int str_banned(char *str, char a, char b);
char *find_start(save_t *current);
char *find_end(save_t *current);
void find_rooms(save_t *current);
void find_other_rooms(save_t *current);
char *error_handling(char *str, int *number_of_ants);
void free_map(rooms_t *head, save_t *list);
void free_all(char *t1, char *t2);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int analytics(char *str);
char *transfo(char *str);
int my_strcmp(char const *s1, char const *s2);
char *get_next_line(void);
int assign_tunnel(rooms_t **other, save_t *list);
int my_put_nbr(int nb);
int check_error(save_t **);
void display_base(save_t *, save_t *, int);
void print_help(void);
void my_putstr(char const *str);
void my_putchar(char c);
void sort(rooms_t **other, char *entrance, char *exit);
void algo(rooms_t *graph, char *exit, int ants);
char *check_last(char **stock);
char **other_path(rooms_t *graph, char **stock);
void my_putstr_error(char *);

#endif
