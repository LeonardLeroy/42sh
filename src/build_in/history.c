/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** history.c
*/

#include "header.h"

int history_command(Global_t *global)
{
    if (global->history)
        for (int i = 0; global->history[i] != NULL; i++)
            mini_printf("%s\n", global->history[i]);
    return NOERROR;
}
