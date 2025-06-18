/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_expansion.c
*/

#include "header.h"

static int get_first_word_length(const char *input)
{
    int i = 0;
    int start = 0;

    while (input[i] && (input[i] == ' ' || input[i] == '\t'))
        i++;
    start = i;
    while (input[i] && input[i] != ' ' && input[i] != '\t')
        i++;
    return i - start;
}

static char *get_first_word(const char *input)
{
    int start = 0;
    int length = 0;
    char *word = NULL;

    length = get_first_word_length(input);
    word = emalloc(length + 1);
    if (!word)
        return NULL;
    strncpy(word, input + start, length);
    word[length] = '\0';
    return word;
}

static char *find_alias_value(global_t *global, const char *key)
{
    alias_t *current = global->aliases;

    while (current) {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return NULL;
}

static char *create_expanded_command(const char *alias_value, const char *rest)
{
    char *new_expanded = NULL;

    new_expanded = emalloc(strlen(alias_value) + strlen(rest) + 2);
    sprintf(new_expanded, "%s %s", alias_value, rest);
    return new_expanded;
}

static char *get_rest_of_command(char *expanded, char const *first_word)
{
    char *rest = expanded + strlen(first_word);

    while (*rest && (*rest == ' ' || *rest == '\t'))
        rest++;
    return rest;
}

int check_alias_loop(char const *first_word, char **visited,
    int visited_count)
{
    for (int i = 0; i < visited_count; i++) {
        if (strcmp(visited[i], first_word) == 0)
            return 1;
    }
    return 0;
}

void free_visited_aliases(char **visited, int visited_count)
{
    for (int i = 0; i < visited_count; i++)
        free(visited[i]);
    free(visited);
}

int process_alias(global_t *global, process_alias_t params)
{
    char *alias_value = NULL;
    char *rest = NULL;
    char *new_expanded = NULL;

    alias_value = find_alias_value(global, params.first_word);
    if (!alias_value)
        return 0;
    if (check_alias_loop(params.first_word, params.visited,
        *(params.visited_count)))
        return 0;
    params.visited[*(params.visited_count)] = my_strdup(params.first_word);
    (*(params.visited_count))++;
    rest = get_rest_of_command(*(params.expanded_ptr), params.first_word);
    new_expanded = create_expanded_command(alias_value, rest);
    if (!new_expanded)
        return 0;
    free(*(params.expanded_ptr));
    *(params.expanded_ptr) = new_expanded;
    return 1;
}

int process_alias_iteration(global_t *global, char **expanded_ptr,
    char **visited, int *visited_count)
{
    char *first_word = NULL;
    process_alias_t params;
    int result = 0;

    first_word = get_first_word(*expanded_ptr);
    if (!first_word)
        return 0;
    params.expanded_ptr = expanded_ptr;
    params.visited = visited;
    params.visited_count = visited_count;
    params.first_word = first_word;
    result = process_alias(global, params);
    free(first_word);
    return result;
}

char *expand_aliases(global_t *global, char *input)
{
    char *expanded = my_strdup(input);
    char **visited = NULL;
    int visited_count = 0;
    int iterations = 0;
    int continue_iteration = 1;

    if (!expanded)
        return input;
    visited = malloc(sizeof(char *) * MAX_VISITED_ALIASES);
    if (!visited) {
        free(expanded);
        return input;
    }
    while (iterations < MAX_ALIAS_ITERATIONS && continue_iteration) {
        continue_iteration = process_alias_iteration
            (global, &expanded, visited, &visited_count);
        iterations++;
    }
    free_visited_aliases(visited, visited_count);
    return expanded;
}
