/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** env.c
*/

#include "header.h"

int env_command(global_t *global)
{
    if (global->env)
        for (int i = 0; global->env[i] != NULL; i++)
            mini_printf("%s\n", global->env[i]);
    return NOERROR;
}
