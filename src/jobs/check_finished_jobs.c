/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** check_finished_jobs.c
*/

#include "header.h"

static char **get_job_cmd_by_pid(linked_list_t *list, pid_t pid)
{
    linked_list_t *tmp = list;

    while (tmp){
        if (((jobs_t *)tmp->data)->pid == pid)
            return ((jobs_t *)tmp->data)->command;
        tmp = tmp->next;
    }
    return NULL;
}

void check_finished_jobs(global_t *global)
{
    int status;
    pid_t pid;
    int job_id;
    char **tmp;

    pid = waitpid(-1, &status, WNOHANG);
    while (pid > 0) {
        job_id = get_job_id_by_pid(global->jobs_list, pid);
        if (WIFEXITED(status) || WIFSIGNALED(status)) {
            tmp = get_job_cmd_by_pid(global->jobs_list, pid);
            printf("[%d] Done\t", job_id);
            print_array(tmp);
            remove_job_by_pid(global->jobs_list, pid);
            my_array_free(&tmp);
        }
        pid = waitpid(-1, &status, WNOHANG);
    }
}
