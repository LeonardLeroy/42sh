/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** get_command.c
*/

#include "header.h"

int get_command(char **input, int iserror, Global_t *global)
{
    size_t size = 0;
    char buffer[MAXINPUT];
    int result;

    if (isatty(STDIN_FILENO)) {
        display_path(iserror);
        result = read_input(buffer, global);
        *input = strdup(buffer);
    } else {
        result = getline(input, &size, stdin);
        for (int i = 0; i < my_strlen(*input); i++)
            (*input)[i] = ((*input)[i] == '\n' ? '\0' : (*input)[i]);
    }
    return result;
}
