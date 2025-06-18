/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** enter.c
*/

#include "header.h"

int key_gestion_enter(char *buffer, global_t *global, int *pos)
{
    display_with_suggestion(buffer, NULL, *pos);
    buffer[global->size_prompt] = '\0';
    global->size_prompt = 0;
    *pos = 0;
    printf("\n");
    return NOERROR;
}
