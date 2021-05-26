/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-yann.joubert
** File description:
** check_map.c
*/

#include "matchstick.h"
#include "my.h"

int stock_sticks(sticks_s *stick)
{
    int nb_sticks = 0;

    for (int i = 0; stick->map[stick->line][i] != '\0'; i++) {
        if (stick->map[stick->line][i] == '|')
            nb_sticks++;
    }
    return (nb_sticks);
}

int check_match(char *buffer, sticks_s *stick)
{
    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        if (buffer[i] < '0' || (buffer[i] == '9' && buffer[i + 1] >= '0' &&
        buffer[i + 1] <= '9') || buffer[i] == '0' || (buffer[i] >= 'a' &&
        buffer[i] <= 'z') || (buffer[i] >= 'A' && buffer[i] <= 'Z')) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    if (my_getnbr(buffer) > stick->match_max) {
        my_printf("Error: you cannot remove more than %d ", stick->match_max);
        my_printf("matches per turn\n");
        return (84);
    }
    if (my_getnbr(buffer) > stock_sticks(stick)) {
        my_printf("Error: not enough matches on this line\n");
        return (84);
    }
    return (0);
}

int check_line(char *buffer, sticks_s *stick)
{
    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        if (buffer[i] < '0' || (buffer[i] == '9' && buffer[i + 1] >= '0' &&
        buffer[i + 1] <= '9') || buffer[i] == '0' || (buffer[i] >= 'a' &&
        buffer[i] <= 'z') || (buffer[i] >= 'A' && buffer[i] <= 'Z')) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    if (my_getnbr(buffer) > stick->line_max) {
        my_printf("Error: this line is out of range\n");
        return (84);
    }
    return (0);
}