/*
** EPITECH PROJECT, 2018
** Lemin
** File description:
** Header file
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct path_s {
   char *rooms;
} path_t;

typedef struct possibility_s {
    int name_pos;
    int nodes;
    struct possibility_s *next;
    struct path_s *next_p;
} possibility_t;

typedef struct general_s {
    struct possibility_s *next;
} general_t;

typedef struct rooms_s{
    char *room_name;
    struct rooms_s *next;
    struct rooms_s **tunnels;
} rooms_t;

typedef struct save_s {
    char *str;
    struct save_s *next;
} save_t;

#endif
