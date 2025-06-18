/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** bg_buildin.c
*/

#include "header.h"

static void resume_process(jobs_t *job)
{
    kill(-job->pid, SIGCONT);
    job->state = RUNNING;
}

static void display(jobs_t *job, int job_id)
{
    printf("[%d]\t", job_id);
    print_array(job->command);
}

int builtin_bg(global_t *global, char *input)
{
    char **args = pass_space_and_tab(input, " \t");
    int job_id;
    jobs_t *job = NULL;

    if (args[1])
        job_id = atoi(&args[1][1]);
    else
        job_id = get_job_id_by_pid(global->jobs_list, global->last_process);
    if (job_id == -1) {
        fprintf(stderr, "bg: No current job.\n");
        return 1;
    }
    job = get_job_by_id(global->jobs_list, job_id);
    if (!job || !job->command) {
        fprintf(stderr, "bg: no such job\n");
        return 1;
    }
    resume_process(job);
    display(job, job_id);
    return 0;
}
