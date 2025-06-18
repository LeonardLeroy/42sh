/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** set_command.c
*/

#include "header.h"

int validate_variable_name(const char *name)
{
    if (!isalpha(name[0]) && name[0] != '_') {
        my_puterror("set: Variable name must begin ");
        my_puterror("with a letter or underscore\n");
        return ERROR;
    }
    for (int i = 0; name[i]; i++) {
        if (!isalnum(name[i]) && name[i] != '_') {
            my_puterror("set: Variable name must contain ");
            my_puterror("only alphanumeric characters or underscore\n");
            return ERROR;
        }
    }
    return NOERROR;
}

int process_set_with_value(global_t *global, char *name, char *value)
{
    if (validate_variable_name(name) != NOERROR)
        return ERROR;
    if (set_local_var(&global->local_vars, name, value) != 0) {
        my_puterror("set: Failed to set variable\n");
        return ERROR;
    }
    return NOERROR;
}

int process_set_without_value(global_t *global, char *name)
{
    if (validate_variable_name(name) != NOERROR)
        return ERROR;
    if (set_local_var(&global->local_vars, name, "") != 0) {
        my_puterror("set: Failed to set variable\n");
        return ERROR;
    }
    return NOERROR;
}

int handle_set_command(global_t *global, char **args)
{
    char *equals = NULL;
    char *name = NULL;
    char *value = NULL;

    if (!args[1]) {
        display_local_vars(global->local_vars);
        return NOERROR;
    }
    equals = strchr(args[1], '=');
    if (equals) {
        *equals = '\0';
        name = args[1];
        value = equals + 1;
        return process_set_with_value(global, name, value);
    } else
        return process_set_without_value(global, args[1]);
}

int set_command(global_t *global, char *input)
{
    char **args = NULL;
    int result = NOERROR;

    args = pass_space_and_tab(input, " \t");
    if (!args)
        return ERROR;
    result = handle_set_command(global, args);
    my_array_free(&args);
    return result;
}
