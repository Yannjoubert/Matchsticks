/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-yann.joubert
** File description:
** change_map.c
*/

#include "my.h"
#include "matchstick.h"

sticks_s *change_map(sticks_s *stick)
{
    int i = my_strlen(stick->map[stick->line]);
    int compt = 0;

    for (; stick->map[stick->line][i] != '|'; i--);
    for (; compt < stick->match; compt++) {
        stick->map[stick->line][i] = ' ';
        i--;
    }
    return (stick);
}