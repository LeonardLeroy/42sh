/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** insert_strarray_in_strarray.c
*/

#include <header.h>

static size_t strarray_len(char **array)
{
    size_t len = 0;

    if (!array)
        return 0;
    while (array[len])
        len++;
    return len;
}

static ssize_t free_strarray(char **array)
{
    if (!array)
        return 0;
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return 0;
}

char **insert_strarray_in_strarray(char **dest, char **src, size_t index)
{
    size_t dest_size = strarray_len(dest);
    size_t src_size = strarray_len(src);
    char **result = malloc((dest_size + src_size) * sizeof(char *));

    if (!result)
        return NULL;
    for (size_t i = 0; i < index && i < dest_size; i++)
        result[i] = strdup(dest[i]);
    for (size_t i = 0; i < src_size; i++)
        result[index + i] = strdup(src[i]);
    for (size_t i = index + 1; i < dest_size; i++)
        result[src_size + i - 1] = strdup(dest[i]);
    result[dest_size + src_size - 1] = NULL;
    free_strarray(dest);
    free_strarray(src);
    return result;
}
