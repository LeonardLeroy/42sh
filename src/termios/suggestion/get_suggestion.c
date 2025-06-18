/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** get_suggestion.c
*/

#include "header.h"

static char *get_entry(DIR *dir, char *word)
{
    struct dirent *entry;
    char *result = NULL;
    size_t word_len = strlen(word);

    entry = readdir(dir);
    while (entry != NULL) {
        if (strncmp(entry->d_name, word, word_len) == 0) {
            result = my_strdup(entry->d_name);
            break;
        }
        entry = readdir(dir);
    }
    closedir(dir);
    free(word);
    return result;
}

static char *file_suggestion(char *last_word)
{
    char *where = NULL;
    char *word = where_am_i(last_word, &where);
    DIR *dir = opendir(where ? where : ".");
    char *result = NULL;

    if (!dir) {
        free(where);
        free(word);
        return NULL;
    }
    result = get_entry(dir, word);
    free(where);
    return result;
}

static char *add_exclamation(const char *input)
{
    size_t len = strlen(input);
    char *result = malloc(len + 2);

    if (!result)
        return NULL;
    result[0] = '!';
    strcpy(result + 1, input);
    return result;
}

static char *gestion_sugg_exclamation(global_t *global, char *last_word)
{
    size_t len = strlen(last_word) - 1;

    for (int i = global->size_history - 1; i >= 0; i--)
        if (strncmp(global->history[i], last_word + 1, len) == 0)
            return add_exclamation(global->history[i]);
    return NULL;
}

static char *gestion_sugg_normal(char *last_word)
{
    size_t len = strlen(last_word);
    char *result;

    for (int i = 0; builtins[i]; i++)
        if (strncmp(builtins[i], last_word, len) == 0)
            return strdup(builtins[i]);
    result = file_suggestion(last_word);
    if (result)
        return result;
    return NULL;
}

char *get_suggestion(const char *buffer, global_t *global)
{
    char *last_word = get_last_word(buffer);
    char *result;

    if (last_word[0] == '!') {
        result = gestion_sugg_exclamation(global, last_word);
        free(last_word);
        if (result)
            return result;
    } else {
        result = gestion_sugg_normal(last_word);
        free(last_word);
        if (result)
            return result;
    }
    return NULL;
}
