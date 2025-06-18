/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** init_global.c
*/

#include "header.h"

global_t init_global(char **envp)
{
    global_t global = {
        .env = NULL,
        .size_env = 0,
        .history = NULL,
        .size_history = 0,
        .index = 0,
        .size_prompt = 0,
        .aliases = NULL,
        .local_vars = NULL,
        .jobs_list = instantiate_linked_list(),
        .last_process = -1,
        .prev_last_process = -1
    };
    int len = my_array_len(envp);

    global.env = my_env_array_dup(envp, len + 1);
    global.env[len] =
        my_strdup("NLSPATH=/usr/share/locale/%L/LC_MESSAGES/"
            "%N.cat:/usr/share/locale/%l/LC_MESSAGES/%N.cat");
    return global;
}
