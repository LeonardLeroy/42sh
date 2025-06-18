/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** fg_buildin.c
*/

#include "header.h"

static void give_term(jobs_t *job, global_t *global)
{
    int status;

    print_array(job->command);
    tcsetpgrp(STDIN_FILENO, job->pid);
    kill(-job->pid, SIGCONT);
    waitpid(job->pid, &status, WUNTRACED);
    tcsetpgrp(STDIN_FILENO, getpgrp());
    test_signal(status);
    if (WIFEXITED(status) || WIFSIGNALED(status))
        remove_job_by_pid(global->jobs_list, job->pid);
    else
        job->state = SUSPENDED;
}

int builtin_fg(global_t *global, char *input)
{
    char **args = pass_space_and_tab(input, " \t");
    int job_id;
    jobs_t *job = NULL;

    if (args[1])
        job_id = atoi(&args[1][1]);
    else
        job_id = get_job_id_by_pid(global->jobs_list, global->last_process);
    if (job_id == -1) {
        fprintf(stderr, "fg: No current job.\n");
        return 1;
    }
    job = get_job_by_id(global->jobs_list, job_id);
    if (!job || !job->command) {
        fprintf(stderr, "fg: no such job\n");
        return 1;
    }
    give_term(job, global);
    return 0;
}
