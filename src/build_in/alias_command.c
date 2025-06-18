/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_command.c
*/

#include "header.h"

static void print_aliases(global_t *global)
{
    alias_t *current = global->aliases;

    while (current) {
        mini_printf("%s\t\'%s\'\n", current->key, current->value);
        current = current->next;
    }
}

static void free_alias_value(alias_t *alias, char *value)
{
    free(alias->value);
    alias->value = my_strdup(value);
}

static void handle_existing_alias(alias_t *current, char *value)
{
    free_alias_value(current, value);
    current->value = my_strdup(value);
}

static alias_t *create_new_alias(char *key, char *value)
{
    alias_t *new_alias = malloc(sizeof(alias_t));

    if (!new_alias) {
        mini_printf("Error: Memory allocation failed for alias\n");
        return NULL;
    }
    new_alias->key = my_strdup(key);
    new_alias->value = my_strdup(value);
    new_alias->next = NULL;
    return new_alias;
}

void add_alias(global_t *global, char *key, char *value)
{
    alias_t *current = global->aliases;
    alias_t *prev = NULL;
    alias_t *new_alias = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            handle_existing_alias(current, value);
            return;
        }
        prev = current;
        current = current->next;
    }
    new_alias = create_new_alias(key, value);
    if (!new_alias)
        return;
    if (prev)
        prev->next = new_alias;
    else
        global->aliases = new_alias;
}

static char *build_alias_value(char **args, int args_count)
{
    char *value = strdup("");
    char *temp = NULL;
    int extra_space;

    for (int i = 2; i < args_count; i++) {
        temp = value;
        extra_space = (i > 2) ? 1 : 0;
        value = malloc(strlen(temp) + strlen(args[i]) + extra_space + 1);
        if (!value) {
            mini_printf("Error: Memory allocation failed\n");
            free(temp);
            return NULL;
        }
        if (i > 2)
            sprintf(value, "%s %s", temp, args[i]);
        else
            sprintf(value, "%s", args[i]);
        free(temp);
    }
    return value;
}

static void print_single_alias(global_t *global, char *key)
{
    alias_t *current = global->aliases;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            mini_printf("%s\t%s\n", key, current->value);
            return;
        }
        current = current->next;
    }
    mini_printf("%s: Alias not found.\n", key);
}

int alias_command_body(global_t *global, char **args, int args_count)
{
    char *value = NULL;

    if (args_count == 2) {
        print_single_alias(global, args[1]);
        my_array_free(&args);
        return NOERROR;
    }
    value = build_alias_value(args, args_count);
    if (value) {
        add_alias(global, args[1], value);
        free(value);
    }
    my_array_free(&args);
    return NOERROR;
}

int alias_command(global_t *global, char *input)
{
    char **args = pass_space_and_tab(input, " \t");
    int args_count = my_array_len(args);

    if (args_count == 1) {
        print_aliases(global);
        my_array_free(&args);
        return NOERROR;
    }
    return alias_command_body(global, args, args_count);
}
