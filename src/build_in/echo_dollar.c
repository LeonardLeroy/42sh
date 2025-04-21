/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** echo_dollar.c
*/

#include "header.h"

static char *find_var_from_env(Global_t *global, char *var)
{
    int var_len = my_strlen(var);

    for (int i = 0; global->env[i] != NULL; ++i)
        if (my_strncmp(global->env[i], var, var_len) == 0)
            return &global->env[i][var_len + 1];
    return NULL;
}

static int echo_var(Global_t *global, char **args, int *ret)
{
    char *tmp;

    if (args[0][1] && args[0][1] == '?') {
        mini_printf("%d\n", *ret);
        my_array_free(&args);
        return 0;
    }
    for (int i = 0; args[i] != NULL; ++i) {
        tmp = find_var_from_env(global, &args[i][1]);
        if (!tmp) {
            fprintf(stderr, "%s: Undefined variable.\n", &args[i][1]);
            return 1;
        }
        mini_printf("%s\n", tmp);
    }
    my_array_free(&args);
    return 0;
}

int echo_command(char *input, Global_t *global, int *ret)
{
    pid_t pid;
    char **args;
    char *new_input = take_after_build_in("echo", input);

    args = pass_space_and_tab(new_input, " \t");
    free(new_input);
    if (args[0] && args[0][0] == VAR_DETECTOR) {
        return echo_var(global, args, ret);
    } else {
        pid = fork();
        if (pid < 0)
            return ERROR;
        *ret = execute(input, global, pid);
    }
    my_array_free(&args);
    return NOERROR;
}
