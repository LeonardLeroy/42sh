/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** where_am_i.c
*/

#include "header.h"

char *where_am_i(char *last_word, char **where)
{
    char *last_slash = strrchr(last_word, '/');
    size_t dir_len;

    if (!last_slash) {
        *where = strdup(".");
        return strdup(last_word);
    }
    dir_len = last_slash - last_word;
    *where = malloc(dir_len + 1);
    if (!*where) {
        *where = strdup("");
        return strdup("");
    }
    memcpy(*where, last_word, dir_len);
    (*where)[dir_len] = '\0';
    return strdup(last_slash + 1);
}
