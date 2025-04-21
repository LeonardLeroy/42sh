/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** execute.c
*/

#include "header.h"

int execute(char *buf, Global_t *global, pid_t pid)
{
    char **args = pass_space_and_tab(buf, " \t");
    int status;
    int result = 0;

    glob_transformation(&args);
    if (pid == 0) {
        result = execute_command(args, 0, global);
        free(args);
        exit(result);
    } else {
        do {
            waitpid(pid, &status, 0);
            result = test_signal(status);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    my_array_free(&args);
    return result;
}
