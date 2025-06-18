/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** unalias_command.c
*/

#include "header.h"

static void free_alias_memory(alias_t *alias)
{
    free(alias->key);
    free(alias->value);
    free(alias);
}

static int remove_alias_node(global_t *global, alias_t *current,
    alias_t *prev)
{
    if (prev)
        prev->next = current->next;
    else
        global->aliases = current->next;
    free_alias_memory(current);
    return 1;
}

static int remove_alias(global_t *global, char *key)
{
    alias_t *current = global->aliases;
    alias_t *prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0)
            return remove_alias_node(global, current, prev);
        prev = current;
        current = current->next;
    }
    return 0;
}

static void process_unalias_args(global_t *global, char **args, int args_count)
{
    for (int arg = 1; arg < args_count; arg++) {
        if (!remove_alias(global, args[arg]))
            mini_printf("%s: Alias not found.\n", args[arg]);
    }
}

int unalias_command(global_t *global, char *input)
{
    char **args = pass_space_and_tab(input, " \t");
    int args_count = my_array_len(args);
    int return_code = 0;

    if (args_count == 1) {
        mini_printf("unalias: Too few arguments.\n");
        return_code = 1;
    } else
        process_unalias_args(global, args, args_count);
    my_array_free(&args);
    return return_code;
}
