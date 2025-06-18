/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** get_job_id_by_pid.c
*/

#include "header.h"

int get_job_id_by_pid(linked_list_t *list, pid_t pid)
{
    linked_list_t *tmp = list;

    if (pid < 0)
        return -1;
    while (tmp){
        if (((jobs_t *)tmp->data)->pid == pid)
            return ((jobs_t *)tmp->data)->id;
        tmp = tmp->next;
    }
    return -1;
}
