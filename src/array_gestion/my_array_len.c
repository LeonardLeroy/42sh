/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_array_len.c
*/

#include "header.h"

int my_array_len(char **array)
{
    int i = 0;

    if (!array)
        return 0;
    for (; array[i]; i++);
    return i;
}
