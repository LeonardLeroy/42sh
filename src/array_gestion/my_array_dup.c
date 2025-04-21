/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_array_dup.c
*/

#include "header.h"

char **my_array_dup(char **array, int size)
{
    char **result = my_env_array_dup(array, size);

    if (array)
        my_array_free(&array);
    return result;
}
