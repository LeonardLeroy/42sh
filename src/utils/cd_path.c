/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** cd_path.c
*/

#include "header.h"

static int handle_special_case(global_t *global, char *new_path,
    char *env_name)
{
    char *env_value = my_getenv(global, env_name);

    if (!env_value)
        return -1;
    my_strncpy(new_path, env_value, MAX_PATH - 1);
    return NOERROR;
}

static int handle_absolute_path_case(char *arg, char *new_path)
{
    my_strncpy(new_path, arg, MAX_PATH - 1);
    return NOERROR;
}

static int handle_relative_path_case(char *arg, char *cwd, char *new_path)
{
    char *temp = str_to_str("/", arg);

    if (!temp)
        return -1;
    my_strncpy(new_path, cwd, MAX_PATH - 1);
    strncat(new_path, temp, MAX_PATH - strlen(new_path) - 1);
    free(temp);
    return NOERROR;
}

int cd_path(char **args, global_t *global, char *cwd, char *new_path)
{
    if (my_array_len(args) < 1 || my_strcmp(args[0], "~") == NOERROR)
        return handle_special_case(global, new_path, "HOME");
    if (my_strcmp(args[0], "-") == NOERROR)
        return handle_special_case(global, new_path, "OLDPWD");
    if (args[0][0] == '/')
        return handle_absolute_path_case(args[0], new_path);
    return handle_relative_path_case(args[0], cwd, new_path);
}
