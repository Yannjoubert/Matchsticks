/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-yann.joubert
** File description:
** remove_stick.c
*/

#include "matchstick.h"
#include "my.h"

int input_null(char *buffer)
{
    if (buffer[0] == '\n') {
        my_printf("Error: invalid input (positive number expected)\n");
        return (84);
    }
    return (0);
}

sticks_s *reset_input(char *buffer, sticks_s *stick)
{
    if (input_null(buffer) == 84)
        return (print_messages(stick));
    return (stick);
}

sticks_s *print_messages(sticks_s *stick)
{
    char *buffer = NULL;
    size_t n = 0;

    my_printf("%s", "Line: ");
    if (getline(&buffer, &n, stdin) < 0)
        return (NULL);
    reset_input(buffer, stick);
    if (check_line(buffer, stick) == 84)
        return (print_messages(stick));
    stick->line = my_getnbr(buffer);
    my_printf("%s", "Matches: ");
    if (getline(&buffer, &n, stdin) < 0)
        return (NULL);
    reset_input(buffer, stick);
    if (check_match(buffer, stick) == 84)
        return (print_messages(stick));
    stick->match = my_getnbr(buffer);
    my_printf("Player removed %d match(es) ", stick->match);
    my_printf("from line %d\n", stick->line);
    return stick;
}