/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** history_gestion.c
*/

#include "header.h"

static void update_history(global_t *global, char *new_history)
{
    global->history[global->size_history] = new_history;
    global->history[global->size_history + 1] = NULL;
    global->size_history += 1;
    global->index = global->size_history;
}

void gestion_history(global_t *global, char *arg)
{
    char *new_history = my_strdup(arg);

    if (my_strlen(new_history) == 0) {
        free(new_history);
        return;
    }
    global->history = my_array_dup(global->history, global->size_history + 1);
    update_history(global, new_history);
}
