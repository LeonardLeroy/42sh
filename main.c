/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** main.c
*/

#include "header.h"

static void handle_sigint(int sig UNUSED)
{
    mini_printf("\n");
    display_path(ERROR);
}

int main(int ac UNUSED, char **av UNUSED,
    char **env)
{
    Global_t global = {NULL, 0, NULL, 0, 0, 0};
    int result;
    int len = my_array_len(env);

    global.env = my_env_array_dup(env, len + 1);
    global.env[len] =
        my_strdup("NLSPATH=/usr/share/locale/%L/LC_MESSAGES/"
            "%N.cat:/usr/share/locale/%l/LC_MESSAGES/%N.cat");
    signal(SIGINT, handle_sigint);
    result = shell(&global);
    my_array_free(&(global.env));
    my_array_free(&(global.history));
    return result;
}
