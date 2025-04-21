/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** extract_word.c
*/

#include "header.h"

static void skip_quoted(const char *str, int *index, int *params[2],
    char *delimiters)
{
    int in_quotes = FALSE;
    char quote_char = '\0';

    if (str[*index] == '"' || str[*index] == '\'') {
        in_quotes = TRUE;
        quote_char = str[*index];
        (*index)++;
        (*(params[0]))++;
    }
    while (str[*index]) {
        if (in_quotes && str[*index] == quote_char)
            break;
        if (!in_quotes && my_strcontain(delimiters, str[*index]))
            break;
        (*index)++;
        (*(params[1]))++;
    }
    if (in_quotes && str[*index] == quote_char)
        (*index)++;
}

char *extract_word(const char *str, int *index, char *delimiters)
{
    int start = *index;
    int length = 0;
    char *word;
    int *params[2] = {&start, &length};

    skip_quoted(str, index, params, delimiters);
    while (str[*index] && !my_strcontain(delimiters, str[*index])) {
        (*index)++;
        length++;
    }
    word = emalloc(length + 1);
    if (!word)
        return NULL;
    for (int i = 0; i < length; i++)
        word[i] = str[start + i];
    word[length] = '\0';
    return word;
}
