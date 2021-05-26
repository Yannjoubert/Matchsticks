/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-yann.joubert
** File description:
** ai.c
*/

#include "matchstick.h"
#include "my.h"
#include <time.h>

int *check_sticks_ai(int *sticks)
{
    int ind = 0;
    int *lines = NULL;
    int count = 0;;

    for (int j = 0; sticks[j] != -1; j++)
        if (sticks[j] != 0)
            count++;
    if (count == 0)
        return NULL;
    lines = malloc(sizeof(int) * (count + 1));
    for (int j = 0; sticks[j] != -1; j++)
        if(sticks[j] != 0)
            lines[ind++] = j;
    lines[ind] = -1;
    return (lines);
}

int *count_sticks_ai(sticks_s *stick)
{
    int ind = 0;
    int *lines = NULL;
    int count = 0;
    int j = 0;

    for (j = 1; stick->map[j + 1] != NULL; j++);
    lines = malloc(sizeof(int) * (j));
    for (j = 1; stick->map[j + 1] != NULL; j++) {
        count = 0;
        for (int i = 1; stick->map[j][i] != '*'; i++)
            if (stick->map[j][i] == '|')
            count++;
        lines[ind++] = count;
    }
    lines[ind] = -1;
    return (lines);
}

int count_int_tab(int *tab)
{
    int i = 0;

    for (; tab[i] != -1; i++);
    return i;
}

int ai_messages(sticks_s **stick)
{
    int *m_perline = count_sticks_ai(*stick);
    int *l_avail = check_sticks_ai(m_perline);

    if (l_avail == NULL) {
        my_putstr("You lost, too bad...");
        return (2);
    }
    (*stick)->line = l_avail[rand() % (count_int_tab(l_avail))] + 1;
    if ((*stick)->match_max > m_perline[(*stick)->line - 1])
        (*stick)->match = rand() % (m_perline[(*stick)->line - 1]) + 1;
    else
        (*stick)->match = rand() % ((*stick)->match_max) + 1;
    my_putchar('\n');
    my_printf("AI's turn...\n");
    my_printf("AI removed %d match(es) ", (*stick)->match);
    my_printf("from line %d\n", (*stick)->line);
    change_map((*stick));
    m_perline = count_sticks_ai(*stick);
    l_avail = check_sticks_ai(m_perline);
    if (l_avail == NULL) {
        display_map((*stick)->map);
        my_putstr("I lost... snif... but I'll get you next time!!");
        return (1);
    }
    free(m_perline);
    free(l_avail);
    return (0);
}