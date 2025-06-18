/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** set_unset_command.c
*/

#include "header.h"

int unset_command(global_t *global, char *input)
{
    char **args = pass_space_and_tab(input, " \t");

    if (!args)
        return ERROR;
    if (!args[1]) {
        my_puterror("unset: Too few arguments.\n");
        my_array_free(&args);
        return ERROR;
    }
    for (int i = 1; args[i]; i++)
        unset_local_var(&global->local_vars, args[i]);
    my_array_free(&args);
    return NOERROR;
}
