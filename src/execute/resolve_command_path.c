/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** resolve_command_path.c
*/

#include "header.h"

static char *search_command_path(const char *command, char *path_copy)
{
    char *token = NULL;
    char *full_path = NULL;

    token = strtok(path_copy, ":");
    while (token) {
        full_path =
            str_to_str(token, str_to_str(my_strdup("/"), (char *) command));
        if (access(full_path, X_OK) == 0)
            return full_path;
        free(full_path);
        token = strtok(NULL, ":");
    }
    return (char *) command;
}

char *resolve_command_path(global_t *global, const char *command)
{
    char *path = NULL;
    char *path_copy = NULL;
    char *result = NULL;

    if (access(command, X_OK) == 0)
        return my_strdup(command);
    path = my_getenv(global, "PATH");
    if (!path)
        path = PATH;
    path_copy = my_strdup(path);
    if (!path_copy)
        return NULL;
    result = search_command_path(command, path_copy);
    free(path_copy);
    return result;
}
