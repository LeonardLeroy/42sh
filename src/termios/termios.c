/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** termios.c
*/

#include "header.h"

static int handle_enter_key(char *suggestion, char *buffer,
    global_t *global, int *pos)
{
    free(suggestion);
    return key_gestion_enter(buffer, global, pos);
}

static void update_suggestion(char *buffer, global_t *global,
    char **suggestion)
{
    if (*suggestion) {
        free(*suggestion);
        *suggestion = NULL;
    }
    *suggestion = get_suggestion(buffer, global);
}

int read_input(char *buffer, global_t *global)
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
            return handle_enter_key(suggestion, buffer, global, &pos);
        key_gestion(c, &pos, buffer, global);
        update_suggestion(buffer, global, &suggestion);
    }
    return NOERROR;
}
