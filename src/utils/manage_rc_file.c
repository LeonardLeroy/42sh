/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** manage_rc_file.c
*/

#include "header.h"

static void add_rc_alias(global_t *global, char *line)
{
    char *alias = NULL;
    char *value = NULL;

    line += 5;
    while (*line == ' ' || *line == '\t')
        line++;
    alias = strtok(line, "=");
    value = strtok(NULL, "\n\0");
    if (alias == NULL || value == NULL) {
        fprintf(stderr, "Error: Invalid alias format in .42rc file.\n");
        return;
    }
    if ((value && value[0] == '\'' && value[strlen(value) - 1] == '\'') ||
        (value && value[0] == '"' && value[strlen(value) - 1] == '"')) {
        value[strlen(value) - 1] = '\0';
        value++;
    }
    add_alias(global, alias, value);
}

void manage_rc_file(global_t *global)
{
    FILE *file = fopen(".42rc", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (file == NULL)
        return;
    for (read = getline(&line, &len, file); read != -1;
        read = getline(&line, &len, file)) {
        if (line[0] == '#')
            continue;
        line[read - 1] = (line[read - 1] == '\n') ? '\0' : line[read - 1];
        if (strncmp(line, "alias", 5) == 0) {
            add_rc_alias(global, line);
            continue;
        }
    }
    free(line);
    fclose(file);
}
