/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** execute.c
*/

#include "header.h"

static char **array_dup(char **array)
{
    int i = 0;
    char **copy = NULL;

    if (!array)
        return NULL;
    for (i = 0; array[i] != NULL; i++);
    copy = emalloc(sizeof(char *) * (i + 1));
    for (i = 0; array[i] != NULL; i++)
        copy[i] = strdup(array[i]);
    copy[i] = NULL;
    return copy;
}

static int is_bg(char **args)
{
    int len = my_array_len(args);

    if (len > 0 && strcmp(args[len - 1], "&") == 0){
        free(args[len - 1]);
        args[len - 1] = NULL;
        return 1;
    }
    return 0;
}

static void handle_child_process(char **args, global_t *global)
{
    int result;

    signal(SIGTSTP, SIG_DFL);
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    setpgid(0, 0);
    result = execute_command(args, 0, global);
    my_array_free(&args);
    exit(result);
}

static int handle_fg_process(pid_t pid)
{
    int status;
    int result;

    tcsetpgrp(STDIN_FILENO, pid);
    waitpid(pid, &status, WUNTRACED);
    tcsetpgrp(STDIN_FILENO, getpgrp());
    result = test_signal(status);
    return result;
}

int execute(char *buf, global_t *global, pid_t pid)
{
    char **args = pass_space_and_tab(buf, " \t");
    int result = 0;
    int bg = is_bg(args);

    glob_transformation(&args);
    if (pid == 0) {
        handle_child_process(args, global);
    } else {
        setpgid(pid, pid);
        if (!bg) {
            result = handle_fg_process(pid);
        } else {
            add_jobs(global, pid, array_dup(args), RUNNING);
            printf("[%d] %d\n", get_job_id_by_pid(global->jobs_list, pid),
                pid);
        }
    }
    my_array_free(&args);
    return result;
}
