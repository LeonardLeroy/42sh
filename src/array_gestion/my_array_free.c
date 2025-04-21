/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_array_free.c
*/

#include "header.h"

void my_array_free(char ***array)
{
    if (!array || !*array)
        return;
    for (int i = 0; (*array)[i]; i++) {
        if (!(*array)[i])
            continue;
        free((*array)[i]);
        (*array)[i] = NULL;
    }
    free(*array);
    *array = NULL;
}
