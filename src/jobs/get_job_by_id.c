/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** get_job_by_id.c
*/

#include "header.h"

jobs_t *get_job_by_id(linked_list_t *list, int id)
{
    linked_list_t *tmp = list;

    if (id < 0 || !tmp->data)
        return NULL;
    while (tmp){
        if (((jobs_t *)tmp->data)->id == id)
            return (jobs_t *)tmp->data;
        tmp = tmp->next;
    }
    return NULL;
}
