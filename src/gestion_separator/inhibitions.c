/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** inhibitions.c
*/

#include "header.h"

char *handle_inhibitions(char *input)
{
    char *new;
    int i = 0;
    int j = 0;

    if (!input)
        return NULL;
    new = malloc(my_strlen(input) + 1);
    if (!new)
        return NULL;
    while (input[i]) {
        if ((input[i] == '\\') && (input[i + 1]))
            i++;
        new[j] = input[i];
        i++;
        j++;
    }
    new[j] = '\0';
    return new;
}
