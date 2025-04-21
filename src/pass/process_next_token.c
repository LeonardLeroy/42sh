/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** process_next_token.c
*/

#include "header.h"

// static void process_word(char **word_array, StringWithDel_t stringwithdel,
//     int *index, int *word_index)
// {
//     char *word =
//         extract_word(stringwithdel.str, index, stringwithdel.delimiters);

//     if (word) {
//         word_array[*word_index] = my_strdup(word);
//         free(word);
//         (*word_index)++;
//     }
// }

// static int is_backtick_block(char c)
// {
//     return (c == '`');
// }

static int skip_backtick_block(const char *str, int index)
{
    const char *start = strchr(&str[index], '`');
    const char *end = strchr(start + 1, '`');

    return (end) ? (end - str + 1) : -1;
}

void process_next_token(char **words, StringWithDel_t *swd, int *index,
    int *word_index)
{
    int new_index;
    char *word;

    if (swd->str[*index] == '`') {
        new_index = skip_backtick_block(swd->str, *index);
        if (new_index == -1) {
            fprintf(stderr, "Error: unmatched backtick.\n");
            return;
        }
        *index = new_index;
        return;
    }
    if (!my_strcontain(swd->delimiters, swd->str[*index])) {
        word = extract_word(swd->str, index, swd->delimiters);
        if (word) {
            words[*word_index] = word;
            (*word_index)++;
        }
    } else
        (*index)++;
}
