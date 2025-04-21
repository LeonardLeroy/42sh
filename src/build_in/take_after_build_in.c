/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Untitled-1
*/

#include "header.h"

static char *new_result(char *str, int begin)
{
    int len = my_strlen(str);
    char *empty;
    int i;
    char *result;

    if (begin >= len) {
        empty = emalloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }
    result = emalloc(sizeof(char) * (len - begin));
    begin++;
    for (i = begin; str[i] != '\0'; i++)
        result[i - begin] = str[i];
    result[i - begin] = '\0';
    return result;
}

char *take_after_build_in(char *delimiter, char *str)
{
    int size = my_strlen(delimiter);
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter[count])
            count++;
        else
            count = (str)[i] == delimiter[0];
        if (count == size)
            return new_result(str, i);
    }
    return NULL;
}
