/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** pass.c
*/

#include "header.h"

char **pass_space_and_tab(char *str, char *delimiters)
{
    int word_count;
    char **words;
    int index = 0;
    int word_index = 0;
    StringWithDel_t swd = {str, delimiters};

    if (!str || !delimiters)
        return NULL;
    word_count = count_words(str, delimiters);
    words = emalloc(sizeof(char *) * (word_count + 1));
    if (!words)
        return NULL;
    while (str[index])
        process_next_token(words, &swd, &index, &word_index);
    words[word_index] = NULL;
    return words;
}
