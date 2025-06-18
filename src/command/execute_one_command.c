/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** execute_one_command.c
*/

#include "header.h"

static int execute_build_in_jobs(enum COMMANDS com, char *input,
    global_t *global, int *ret UNUSED)
{
    switch (com) {
        case JOBS:
            return jobs_buildin(global);
        case FG:
            return builtin_fg(global, input);
        case BG:
            return builtin_bg(global, input);
        case COPILOT:
            return buildin_copilot(global);
        default:
            return ERROR;
    }
}

static int execute_build_in_scripting(enum COMMANDS com, char *input,
    global_t *global, int *ret UNUSED)
{
    switch (com) {
        case FOREACH:
            return foreach_command(global);
        case WHICH:
            return which_command(global);
        case WHERE:
            return where_command(global);
        case IF:
            return if_command(global);
        case ELSE:
            return else_command(global);
        case REPEAT:
            return repeat_command(global);
        default:
            return execute_build_in_jobs(com, input, global, ret);
    }
}

static int execute_build_in2(enum COMMANDS com, char *input, global_t *global,
    int *ret UNUSED)
{
    switch (com) {
        case LUCY:
            return print_file("lucy");
        case DOOM:
            return print_file("doom_slayer");
        case EXCLAMATION:
            return exclamation_command(global, input);
        case CREDITS:
            return print_file("credits");
        case ALIAS:
            return alias_command(global, input);
        case UNALIAS:
            return unalias_command(global, input);
        case SET:
            return set_command(global, input);
        case UNSET:
            return unset_command(global, input);
        default:
            return execute_build_in_scripting(com, input, global, ret);
    }
}

static int execute_build_in(enum COMMANDS com, char *input, global_t *global,
    int *ret)
{
    switch (com) {
        case CD:
            return cd_command(input, global);
        case SETENV:
            return setenv_command(input, global);
        case UNSETENV:
            return unsetenv_command(input, global);
        case ENTER:
            return *ret;
        case ENV:
            return env_command(global);
        case ECHO_IN:
            return echo_command(input, global, ret);
        case HISTORY:
            return history_command(global);
        case MARIN:
            return print_file("marin_kitagawa");
        default:
            return execute_build_in2(com, input, global, ret);
    }
}

int execute_one_command(char *INPUT, int *result, global_t *global)
{
    pid_t pid;
    enum COMMANDS COM;

    COM = is_build_in(INPUT);
    if (COM == EXIT)
        return -1;
    if (COM != NOTHING) {
        *result = execute_build_in(COM, INPUT, global, result);
        return *result;
    }
    pid = fork();
    if (pid < 0)
        return ERROR;
    *result = execute(INPUT, global, pid);
    return *result;
}
