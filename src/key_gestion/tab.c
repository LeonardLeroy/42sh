/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** tab.c
*/

#include "header.h"

int key_gestion_tab(char *suggestion, char *buffer, int *pos, Global_t *global)
{
    int len = strlen(suggestion);
    int buf_len = strlen(buffer);
    char *last_word = get_last_word(buffer);
    size_t len_word = strlen(last_word);
    int temp = buf_len;

    for (size_t i = *pos; i < buf_len + (len - len_word); i++) {
        buffer[temp] = suggestion[i - (buf_len - len_word)];
        temp++;
        (*pos)++;
        global->size_prompt++;
    }
    buffer[temp] = '\0';
    display_with_suggestion(buffer, NULL, *pos);
    return NOERROR;
}
