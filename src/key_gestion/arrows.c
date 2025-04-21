/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** arrows.c
*/

#include "header.h"

static int gestion_arrows(int *pos, Global_t *global, char *seq)
{
    if (seq[1] == 'A' && global->index > 0) {
        global->index--;
        return TRUE;
    }
    if (seq[1] == 'B' && global->index < global->size_history) {
        global->index++;
        return TRUE;
    }
    if (seq[1] == 'C' && *pos < global->size_prompt) {
        (*pos)++;
        return TRUE;
    }
    if (seq[1] == 'D' && *pos > 0) {
        (*pos)--;
        return TRUE;
    }
    return FALSE;
}

void key_gestion_arrow(Global_t *global, char *buffer, int *pos)
{
    char seq[2];
    int temp;

    if (read(0, &seq[0], 1) != 1 || read(0, &seq[1], 1) != 1)
        return;
    if (seq[0] == '[') {
        temp = gestion_arrows(pos, global, seq);
        if (global->index >= 0 && global->index < global->size_history
            && global->history[global->index] != NULL
            && (seq[1] == 'A' || seq[1] == 'B')) {
            display_path(0);
            printf("%s", global->history[global->index]);
            strcpy(buffer, global->history[global->index]);
            global->size_prompt = strlen(buffer);
            *pos = global->size_prompt;
        }
        if ((seq[1] == 'D' || seq[1] == 'C') && temp)
            printf("\033[%c", seq[1]);
        fflush(stdout);
    }
}
