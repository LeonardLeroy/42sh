/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** termios.c
*/

#include "header.h"

int read_input(char *buffer, Global_t *global)
{
    int pos = 0;
    char c;
    char *suggestion = NULL;

    while (TRUE) {
        if (read(STDIN_FILENO, &c, 1) != 1)
            continue;
        if (c == '\t' && suggestion) {
            key_gestion_tab(suggestion, buffer, &pos, global);
            continue;
        }
        if (c == '\n')
            return key_gestion_enter(buffer, global, &pos);
        key_gestion(c, &pos, buffer, global);
        suggestion = get_suggestion(buffer, global);
    }
    return NOERROR;
}

// int read_input(char *buffer, Global_t *global)
// {
//     int pos = 0;
//     char c;

//     while (TRUE) {
//         if (read(STDIN_FILENO, &c, 1) != 1)
//             continue;
//         switch (c) {
//             case '\n':
//                 return key_gestion_enter(buffer, global, &pos);
//             case 12:
//                 strcpy(buffer, "clear");
//                 return NOERROR;
//             default:
//                 key_gestion(c, &pos, buffer, global);
//         }
//     }
//     return NOERROR;
// }
