/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** execute_one_command.c
*/

#include "header.h"

static int execute_build_in2(enum COMMANDS com, char *input, Global_t *global,
    int *ret UNUSED)
{
    switch (com) {
        case EXCLAMATION:
            return exclamation_command(global, input);
        case CREDITS:
            return print_file("credits");
        default:
            return ERROR;
    }
}

static int execute_build_in(enum COMMANDS com, char *input, Global_t *global,
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

int execute_one_command(char *INPUT, int *result, Global_t *global)
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
