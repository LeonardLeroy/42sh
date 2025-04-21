/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** count_words.c
*/

#include "header.h"

static int update_in_quote(int in_quotes, char *str, char *quote_char, int i)
{
    if ((str[i] == '"' || str[i] == '\'') && (i == 0 || str[i - 1] != '\\')) {
        if (in_quotes && str[i] == *quote_char)
            in_quotes = FALSE;
        if (!(in_quotes && str[i] == *quote_char) && !in_quotes) {
            in_quotes = TRUE;
            *quote_char = str[i];
        }
    }
    return in_quotes;
}

int count_words(char *str, char *delimiters)
{
    int count = 0;
    int in_word = FALSE;
    int in_quotes = FALSE;
    char quote_char = '\0';

    for (int i = 0; str[i]; i++) {
        in_quotes = update_in_quote(in_quotes, str, &quote_char, i);
        if (!in_quotes && my_strcontain(delimiters, str[i])) {
            count++;
            in_word = FALSE;
        }
        if (!in_quotes && !my_strcontain(delimiters, str[i]) && !in_word) {
            count++;
            in_word = TRUE;
        }
    }
    return count;
}
