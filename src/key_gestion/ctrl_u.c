/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** ctrl_u.c
*/

#include "header.h"

void key_gestion_u(global_t *global, int *pos, char *buffer)
{
    for (int i = 0; i < global->size_prompt; i++)
        buffer[i] = buffer[i + *pos];
    global->size_prompt = global->size_prompt - *pos;
    display_path(0);
    printf("%s", buffer);
    for (int i = 0; i < global->size_prompt; i++)
        printf("\033[D");
    *pos = 0;
    fflush(stdout);
}
