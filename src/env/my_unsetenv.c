/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_unsetenv.c
*/

#include "header.h"

static void move_others(Global_t *global, int len, int i)
{
    for (int j = i; j < len - 1; j++)
        (global->env)[j] = (global->env)[j + 1];
}

void my_unsetenv(Global_t *global, char *name)
{
    int len = my_array_len(global->env);
    int length = my_strlen(name);
    int new_len;

    if (my_strcmp(name, "*") == 0) {
        for (int i = 0; (global->env)[i] != NULL; i++)
            (global->env)[i] = NULL;
        return;
    }
    for (int i = 0; i < len; i++) {
        if (my_strncmp((global->env)[i], name, length) == 0
            && (global->env)[i][length] == '=') {
            free((global->env)[i]);
            DEBUG("len: %d\n", len);
            move_others(global, len, i);
            new_len = my_array_len(global->env) - 1;
            (global->env)[new_len] = NULL;
            return;
        }
    }
}
