/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** getenv.c
*/

#include "header.h"

char *my_getenv(global_t *global, char *name)
{
    int len = my_strlen(name);

    for (int i = 0; global->env[i] != NULL; i++)
        if (my_strncmp(global->env[i], name, len) == 0
            && global->env[i][len] == '=')
            return &global->env[i][len + 1];
    return NULL;
}
