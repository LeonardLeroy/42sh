/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** unsetenv.c
*/

#include "header.h"

int unsetenv_command(char *input, global_t *global)
{
    char **args;
    char *after_input = NULL;

    after_input = take_after_build_in("unsetenv", input);
    args = pass_space_and_tab(after_input, " \t");
    free(after_input);
    if (!args[0])
        my_puterror("unsetenv: Too few arguments.\n");
    for (int i = 0; args[i] != NULL; i++)
        my_unsetenv(global, args[i]);
    my_array_free(&args);
    return NOERROR;
}
