/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** print_array.c
*/

#include "header.h"

int print_array(char **array)
{
    if (!array)
        return 1;
    for (int i = 0; array[i] != NULL; ++i)
        printf("%s ", array[i]);
    printf("\n");
    return 0;
}
