/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** get_suggestion.c
*/

#include "header.h"

const char *builtins[] = {"exit", "cd", "setenv", "unsetenv", "env", "enter",
    "history", "echo", "marin"};

static char *where_am_i(char *last_word, char **where)
{
    char *last_slash = strrchr(last_word, '/');
    size_t dir_len;

    if (!last_slash) {
        *where = strdup(".");
        return strdup(last_word);
    }
    dir_len = last_slash - last_word;
    *where = malloc(dir_len + 1);
    if (!*where)
        return NULL;
    strncpy(*where, last_word, dir_len);
    (*where)[dir_len] = '\0';
    return strdup(last_slash + 1);
}

static char *file_suggestion(char *last_word)
{
    char *where;
    char *word = where_am_i(last_word, &where);
    DIR *dir = opendir(where);
    struct dirent *entry = readdir(dir);

    if (!dir)
        return NULL;
    while (entry != NULL) {
        if (strncmp(entry->d_name, word, strlen(word)) != 0) {
            entry = readdir(dir);
            continue;
        }
        closedir(dir);
        if (strcmp(where, ".") != 0)
            return str_to_str(where, str_to_str("/", entry->d_name));
        else
            return my_strdup(entry->d_name);
    }
    closedir(dir);
    return NULL;
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

static char *gestion_sugg_exclamation(Global_t *global, char *last_word)
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

char *get_suggestion(const char *buffer, Global_t *global)
{
    char *last_word = get_last_word(buffer);
    char *result;

    if (last_word[0] == '!') {
        result = gestion_sugg_exclamation(global, last_word);
        if (result)
            return result;
    } else {
        result = gestion_sugg_normal(last_word);
        if (result)
            return result;
    }
    return NULL;
}

// char *get_suggestion(const char *buffer, Global_t *global)
// {
//     if (buffer[0] == '!') {
//         for (int i = global->size_history - 2; i >= 0; i--) {
//             if (strncmp(global->history[i], buffer + 1, strlen(buffer) - 1)
//                 == 0) {
//                 return add_exclamation(global->history[i]);
//             }
//         }
//     } else {
//         const char *builtins[] = {"cd", "ls", "echo", "exit", NULL};
//         for (int i = 0; builtins[i]; i++)
//             if (strncmp(builtins[i], buffer, strlen(buffer)) == 0)
//                 return strdup(builtins[i]);
//         // Bonus : lecture de fichiers dans le répertoire courant
//     }
//     return NULL;
// }
