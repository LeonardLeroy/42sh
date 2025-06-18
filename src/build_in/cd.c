/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** cd.c
*/

#include "header.h"

static int validate_args(char **args)
{
    if (my_array_len(args) > 1) {
        my_puterror("cd: Too many arguments.\n");
        return ERROR;
    }
    return NOERROR;
}

static int handle_cd_path(char **args, global_t *global, char *cwd)
{
    char new_path[MAX_PATH];

    if (cd_path(args, global, cwd, new_path) == -1) {
        my_puterror("cd: No such directory.\n");
        return ERROR;
    }
    my_setenv(global, "OLDPWD", cwd);
    if (chdir(new_path) != 0) {
        my_puterror(args[0]);
        my_puterror(": ");
        my_puterror(strerror(errno));
        my_puterror(".\n");
        return ERROR;
    }
    return NOERROR;
}

static void cleanup_resources(char **args, char *input)
{
    if (input)
        free(input);
    if (args)
        my_array_free(&args);
}

int cd_command(char *input, global_t *global)
{
    char buf[SIZE_PATH];
    char *cwd = getcwd(buf, sizeof(char) * SIZE_PATH);
    char **args = NULL;
    int result = NOERROR;

    input = take_after_build_in("cd", input);
    if (!input)
        return ERROR;
    args = pass_space_and_tab(input, " \t");
    if (!args) {
        free(input);
        return ERROR;
    }
    if (validate_args(args) != NOERROR) {
        cleanup_resources(args, input);
        return ERROR;
    }
    result = handle_cd_path(args, global, cwd);
    cleanup_resources(args, input);
    return result;
}
