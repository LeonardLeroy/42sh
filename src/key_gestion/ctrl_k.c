/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** ctrl_k.c
*/

#include "header.h"

void key_gestion_k(global_t *global, int *pos, char *buffer)
{
    for (int i = *pos; i < global->size_prompt; i++) {
        buffer[i] = '\0';
        global->size_prompt--;
    }
    display_path(0);
    printf("%s", buffer);
    fflush(stdout);
}
