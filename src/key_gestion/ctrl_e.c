/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** ctrl_e.c
*/

#include "header.h"

void key_gestion_e(Global_t *global, int *pos)
{
    for (int i = *pos; i < global->size_prompt; i++)
        printf("\033[C");
    *pos = global->size_prompt;
    fflush(stdout);
}
