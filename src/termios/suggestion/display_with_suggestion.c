/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** display_with_suggestion.c
*/

#include "header.h"

void display_with_suggestion(const char *buffer, const char *suggestion,
    int pos)
{
    char *last_word = get_last_word(buffer);
    size_t len;
    int added;

    if (!last_word)
        return;
    len = strlen(last_word);
    display_path(0);
    printf("%s", buffer);
    if (suggestion && suggestion[0]) {
        if (strlen(suggestion) > len)
            printf(ANSI_COLOR_GRAY "%s" ANSI_COLOR_RESET, suggestion + len);
    }
    added = (suggestion && suggestion[0] && len <= strlen(suggestion))
        ? strlen(suggestion + len) : 0;
    for (int i = strlen(buffer) + added; i > pos; i--)
        printf("\033[D");
    free(last_word);
    fflush(stdout);
}
