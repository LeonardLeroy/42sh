/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** get_last_word.c
*/

#include "header.h"

static char *transform_last_word(int word_len, const char *buffer, int start)
{
    char *last_word;

    last_word = malloc(word_len + 1);
    if (!last_word)
        return NULL;
    strncpy(last_word, buffer + start, word_len);
    last_word[word_len] = '\0';
    return last_word;
}

char *get_last_word(const char *buffer)
{
    int len = strlen(buffer);
    int end = len - 1;
    int start;
    int word_len;

    while (end >= 0 && buffer[end] == ' ')
        end--;
    start = end;
    while (start >= 0 && buffer[start] != ' ' && buffer[start] != '|'
        && buffer[start] != '&' && buffer[start] != ';')
        start--;
    start++;
    word_len = end - start + 1;
    if (word_len <= 0)
        return strdup("");
    return transform_last_word(word_len, buffer, start);
}
