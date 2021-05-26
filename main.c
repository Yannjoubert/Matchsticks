/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-yann.joubert
** File description:
** main.c
*/

#include "my.h"
#include "matchstick.h"

int play_game(char **av)
{
    int i = 0;
    sticks_s *stick = malloc(sizeof(*stick));

    stick->line_max = my_getnbr(av[1]);
    stick->match_max = my_getnbr(av[2]);
    stick->map = put_in_map(stick->line_max);
    display_map(stick->map);
    while (1) {
        my_putchar('\n');
        my_printf("Your turn:\n");
        if ((stick = print_messages(stick)) == NULL)
            return (0);
        change_map(stick);
        display_map(stick->map);
        i = ai_messages(&stick);
        if (i != 0)
            return (i);
        display_map(stick->map);
    }
}

int main(int ac, char **av)
{
    int matches = 0;
    int line = 0;

    if (ac != 3) {
        write(2, "Invalid argument\n", 18);
        return (84);
    }
    line = my_getnbr(av[1]);
    matches = my_getnbr(av[2]);
    if (line < 2 || line > 99 || matches < 1) {
        write(2, "Invalid argument\n", 18);
        return (84);
    }
    return (play_game(av));
}