/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** split_string.c
*/

#include "header.h"

char **split_string(const char *str, const char *delimiter, int *is_in)
{
    char **result = malloc(3 * sizeof(char *));
    int pos = search_delim(str, delimiter);

    result[0] = NULL;
    result[1] = NULL;
    result[2] = NULL;
    if (pos == -1) {
        *is_in = !my_strstr((char *) str, delimiter) ? FALSE : TRUE;
        result[0] = my_strdup(str);
        return result;
    }
    result[0] = my_strndup(str, pos);
    result[1] = my_strdup(&str[pos + my_strlen(delimiter)]);
    return result;
}
