/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** gestion_multi_lines.c
*/

#include "header.h"

static char *extract_delimiter(const char *input)
{
    char *start = strstr(input, "<<");
    char *end;
    char *result;

    if (!start)
        return NULL;
    start += 2;
    while (*start == ' ')
        start++;
    end = start;
    while (*end && *end != ' ' && *end != '\n')
        end++;
    result = strndup(start, end - start);
    return result;
}

static int gestion_one_line(const char *line, const char *delim,
    char **multi_lines)
{
    static size_t total_size = 0;

    if ((strcmp(line, delim) == 0)
        || (strlen(line) == strlen(delim) + 1
            && line[strlen(delim)] == '\n')) {
        return ERROR;
    }
    total_size += strlen(line);
    *multi_lines = realloc(*multi_lines, total_size + 1);
    if (!(*multi_lines))
        return -1;
    strcat(*multi_lines, line);
    return NOERROR;
}

static void update_input(char **input, const char *multi_lines)
{
    size_t new_size = strlen(*input) + strlen(multi_lines) + 10;
    char *new_command = malloc(new_size);
    char *pos = strstr(*input, "<<");
    size_t head_len = pos - *input;

    strncpy(new_command, *input, head_len);
    new_command[head_len] = '\0';
    strcat(new_command, "<< ");
    strcat(new_command, multi_lines);
    free(*input);
    *input = new_command;
}

void gestion_multi_lines(char **input, global_t *global)
{
    char *delim = extract_delimiter(*input);
    char *multi_lines = NULL;
    char *line = NULL;
    size_t size_line = 0;

    multi_lines = strdup("");
    if (!multi_lines)
        return;
    disable_raw_mode(&(global->term));
    while (getline(&line, &size_line, stdin) != -1)
        if (gestion_one_line(line, delim, &multi_lines) == ERROR)
            break;
    enable_raw_mode(&(global->term));
    update_input(input, multi_lines);
    free(multi_lines);
    free(line);
}
