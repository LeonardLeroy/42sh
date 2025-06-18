/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** jobs_buildin.c
*/

#include "header.h"

int jobs_buildin(global_t *global)
{
    my_apply_on_nodes(global->jobs_list, &display_jobs);
    return 0;
}
