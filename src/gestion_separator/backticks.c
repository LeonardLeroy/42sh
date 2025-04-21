/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** backticks.c
*/

#include "header.h"

static char *get_command_output(char *cmd)
{
    FILE *fp;
    char *result = malloc(4096);

    if (!result)
        return NULL;
    result[0] = '\0';
    fp = popen(cmd, "r");
    if (fp == NULL)
        return NULL;
    if (fread(result, 1, 4095, fp) <= 0)
        return NULL;
    pclose(fp);
    return result;
}

static char *extract_and_execute_command(const char *start, const char *end)
{
    size_t cmd_len = end - start - 1;
    char *cmd = my_strndup(start + 1, cmd_len);
    char *output = get_command_output(cmd);

    free(cmd);
    return output;
}

static char *find_and_process_backticks(const char *input, char **start,
    char **end, char **output)
{
    if (!input)
        return NULL;
    *start = strchr(input, '`');
    if (!*start)
        return my_strdup(input);
    *end = strchr(*start + 1, '`');
    if (!*end)
        return my_strdup(input);
    *output = extract_and_execute_command(*start, *end);
    if (!*output)
        return NULL;
    return NULL;
}

char *handle_backticks(char *input)
{
    char *start = NULL;
    char *end = NULL;
    char *output = NULL;
    char *new = NULL;
    size_t new_size = 0;

    new = find_and_process_backticks(input, &start, &end, &output);
    if (new != NULL)
        return new;
    new_size = my_strlen(input) - (end - start + 1) + my_strlen(output) + 1;
    new = malloc(new_size);
    if (!new)
        return NULL;
    my_strncpy(new, input, start - input);
    new[start - input] = '\0';
    my_strcat(new, output);
    my_strcat(new, end + 1);
    free(output);
    return new;
}
