/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_env_array_dup.c
*/

#include "header.h"

char **my_env_array_dup(char **array, int size)
{
    char **result = emalloc(sizeof(char *) * (size + 1));

    if (!result)
        return NULL;
    for (int i = 0; i < size; i++)
        if (i < size - 1)
            result[i] = my_strdup(array[i]);
        else
            result[i] = NULL;
    result[size] = NULL;
    return result;
}
