/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** setenv.c
*/

#include "header.h"

char **my_setenv(global_t *global, char *name, char *value)
{
    int len = my_strlen(name);
    char *new_name = str_to_str(name, "=");
    int i = 0;
    int index = -1;

    for (; (global->env)[i] != NULL; i++)
        if (my_strncmp((global->env)[i], name, len) == 0
            && (global->env)[i][len] == '=')
            index = i;
    if (index == -1) {
        global->env = my_array_dup(global->env, my_array_len(global->env) + 1);
        (global->env)[i + 1] = NULL;
        index = i;
    }
    free((global->env)[index]);
    (global->env)[index] = str_to_str(new_name, value);
    free(new_name);
    return global->env;
}
