/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** jobs.c
*/

#include "header.h"

void add_jobs(global_t *global, pid_t pid, char **command,
    enum JOBS_STATE state)
{
    static int id = 0;
    jobs_t *jobs = emalloc(sizeof(jobs_t));

    ++id;
    jobs->id = id;
    jobs->pid = pid;
    jobs->command = command;
    jobs->state = state;
    jobs->is_notify = 0;
    global->last_process = pid;
    add_node(global->jobs_list, jobs);
}
