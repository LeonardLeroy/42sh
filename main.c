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

int main(int ac UNUSED, char **av UNUSED, char **env)
{
    global_t global = init_global(env);
    int result;

    manage_rc_file(&global);
    signal(SIGINT, handle_sigint);
    result = shell(&global);
    free_global(&global);
    return result;
}
