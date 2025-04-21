/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** is_all_spaces.c
*/

#include "header.h"

int is_all_spaces(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return FALSE;
    return TRUE;
}
