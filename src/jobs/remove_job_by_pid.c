/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** remove_job_by_pid.c
*/

#include "header.h"

static int cmp_pid(void *data, void *pid)
{
    if (((jobs_t *)data)->pid == ((jobs_t *)pid)->pid)
        return 1;
    return 0;
}

void remove_job_by_pid(linked_list_t *list, pid_t pid)
{
    jobs_t tmp[] = {{0, pid, NULL, 0, 0}};

    my_delete_nodes(list, tmp, &cmp_pid);
}
