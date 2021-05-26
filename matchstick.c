/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-yann.joubert
** File description:
** matchstick.c
*/

#include "my.h"
#include "matchstick.h"

char **malloc_map(int size)
{
    char **map = NULL;
    int i = 0;

    map = malloc(sizeof(char *) * (size + 3));
    while (i != size + 2) {
        map[i] = malloc(sizeof(char) * (size * 2 + 3));
        i = i + 1;
    }
    map[i] = NULL;
    return map;
}

char *print_caract(char *str, char caract, int size)
{
    int i = 0;

    while (i < size) {
        str[i] = caract;
        i = i + 1;
    }
    str[i] = '\0';
    return (str);
}

char **put_in_map(int size)
{
    char **map = NULL;
    int i = 1;
    int x = 0;
    int j = 1;

    map = malloc_map(size);
    map[0] = print_caract(map[0], '*', (size * 2 + 1));
    for (; i < size + 1; i++) {
        map[i] = print_caract(map[i], ' ', (size * 2 + 1));
        map[i][0] = '*';
        map[i][size * 2] = '*';
    }
    map[size + 1] = print_caract(map[size + 1], '*', (size * 2 + 1));
    i = 0;
    for (; j <= size; i++, j++) {
        x = (size - i);
        for (; x < (size + i + 1); x++)
            map[j][x] = '|';
    }
    return map;
}

void display_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        my_putstr(map[i]);
        my_putchar('\n');
        i = i + 1;
    }
}