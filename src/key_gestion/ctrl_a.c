/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** ctrl_a.c
*/

#include "header.h"

void key_gestion_a(int *pos)
{
    for (int i = *pos; i > 0; i--)
        printf("\033[D");
    *pos = 0;
    fflush(stdout);
}
