/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-yann.joubert
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct sticks_t {
    char **map;
    int line_max;
    int match_max;
    int line;
    int match;
} sticks_s;

//matchstick.c
char **malloc_map(int size);
char *print_caract(char *str, char c, int size);
char **put_in_map(int size);
void display_map(char **map);

//main.c
int play_game(char **map);

//input.c
int stock_sticks(sticks_s *stick);
int input_null(char *buffer);
sticks_s *reset_input(char *buffer, sticks_s *stick);
sticks_s *print_messages(sticks_s *stick);

//check_map.c
int check_line(char *buffer, sticks_s *stick);
int check_match(char *buffer, sticks_s *stick);

//change_map.c
sticks_s *change_map(sticks_s *stick);

//ai.c
int ai_messages(sticks_s **stick);

#endif