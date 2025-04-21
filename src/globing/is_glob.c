/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** is_glob.c
*/

#include "header.h"

int is_glob(char *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (strchr(GLOBINGS_CHARS, str[i]) != NULL)
            return TRUE;
    return FALSE;
}
