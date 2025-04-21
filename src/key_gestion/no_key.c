/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** no_key.c
*/

#include "header.h"

void no_key_gestion(int *pos, char *buffer, char c, Global_t *global)
{
    char *suggestion;

    if (*pos < MAXINPUT - 1) {
        for (int i = global->size_prompt; i > *pos; i--)
            buffer[i] = buffer[i - 1];
        buffer[*pos] = c;
        (*pos)++;
        global->size_prompt++;
        buffer[global->size_prompt] = '\0';
        suggestion = get_suggestion(buffer, global);
        display_with_suggestion(buffer, suggestion, *pos);
        free(suggestion);
    }
}

// void no_key_gestion(int *pos, char *buffer, char c, Global_t *global)
// {
//     if (*pos < MAXINPUT - 1) {
//         for (int i = global->size_prompt; i > *pos; i--)
//             buffer[i] = buffer[i - 1];
//         buffer[*pos] = c;
//         (*pos)++;
//         global->size_prompt++;
//         buffer[global->size_prompt] = '\0';
//         display_path(0);
//         printf("%s", buffer);
//         for (int i = *pos; i < global->size_prompt; i++)
//             printf("\033[D");
//         fflush(stdout);
//     }
// }
