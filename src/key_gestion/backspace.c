/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** backspace.c
*/

#include "header.h"

void key_gestion_backspace(int *pos, Global_t *global, char *buffer)
{
    if (*pos > 0) {
        for (int i = *pos - 1; i < global->size_prompt - 1; i++)
            buffer[i] = buffer[i + 1];
        if (*pos < global->size_prompt) {
            buffer[global->size_prompt - 1] = '\0';
            display_path(0);
            printf("%s", buffer);
        } else
            printf("\b \b");
        for (int i = *pos; i < global->size_prompt; i++)
            printf("\033[D");
        global->size_prompt--;
        (*pos)--;
        fflush(stdout);
    }
}
