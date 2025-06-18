/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** history.c
*/

#include "header.h"

int history_command(global_t *global)
{
    int history_size = 0;
    int width = 0;

    if (!global->history)
        return NOERROR;
    for (int i = 0; global->history[i] != NULL; i++)
        history_size++;
    width = (history_size > 0) ? (int)log10(history_size) + 1 : 1;
    width = (width > 5) ? width : 5;
    for (int i = 0; i < history_size; i++)
        printf("%*d  %s\n", width, i + 1, global->history[i]);
    return NOERROR;
}
