/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** free_global.c
*/

#include "header.h"

void free_global(global_t *global)
{
    my_array_free(&(global->env));
    my_array_free(&(global->history));
    free_jobs(&(global->jobs_list));
    free_aliases(&(global->aliases));
    free_local_vars(&(global->local_vars));
}
