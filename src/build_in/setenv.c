/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** setenv.c
*/

#include "header.h"

static int is_authorized(char *str)
{
    if (IS_NUMERICAL(str[0])) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return FALSE;
    }
    for (int i = 0; str[i] != '\0'; i++)
        if (!(IS_ALPHANUMERICAL(str[i]) || str[i] == '_')) {
            my_puterror("setenv: ");
            my_puterror(
                "Variable name must contain alphanumeric characters.\n");
            return FALSE;
        }
    return TRUE;
}

int setenv_command(char *input, Global_t *global)
{
    char *after_input = NULL;
    char **args;

    after_input = take_after_build_in("setenv", input);
    args = pass_space_and_tab(after_input, " \t");
    free(after_input);
    if (!args[0]) {
        my_array_free(&args);
        return env_command(global);
    }
    if (!is_authorized(args[0])) {
        my_array_free(&args);
        return ERROR;
    }
    global->env = my_setenv(global, args[0], (!args[1]) ? "" : args[1]);
    my_array_free(&args);
    return NOERROR;
}
