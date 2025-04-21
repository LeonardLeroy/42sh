/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** key_gestion.c
*/

#include "header.h"

void key_gestion_2(char c, int *pos, char *buffer, Global_t *global)
{
    switch (c) {
        case 11:
            key_gestion_k(global, pos, buffer);
            break;
        case 4:
            printf("exit\n");
            exit(NOERROR);
        case 12:
            strcpy(buffer, "clear");
            break;
        default:
            no_key_gestion(pos, buffer, c, global);
    }
}

void key_gestion(char c, int *pos, char *buffer, Global_t *global)
{
    switch (c) {
        case 127:
        case 8:
            key_gestion_backspace(pos, global, buffer);
            break;
        case 27:
            key_gestion_arrow(global, buffer, pos);
            break;
        case 1:
            key_gestion_a(pos);
            break;
        case 5:
            key_gestion_e(global, pos);
            break;
        case 21:
            key_gestion_u(global, pos, buffer);
            break;
        default:
            key_gestion_2(c, pos, buffer, global);
    }
}
