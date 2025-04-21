/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** execute_tree.c
*/

#include "header.h"

static int process_command(tree_t *tree)
{
    char *temp = NULL;
    char *processed_command = NULL;

    if (is_all_spaces(tree->command))
        return NOERROR;
    temp = handle_inhibitions(tree->command);
    if (temp == NULL)
        return ERROR;
    processed_command = handle_backticks(temp);
    if (processed_command == NULL) {
        free(temp);
        return ERROR;
    }
    if (tree->command_allocated)
        free(tree->command);
    tree->command = strdup(processed_command);
    tree->command_allocated = 1;
    free(temp);
    free(processed_command);
    return NOERROR;
}

int execute_tree(tree_t *tree, int *result, Global_t *global)
{
    int res;

    res = process_command(tree);
    if (res == ERROR)
        return ERROR;
    res = handle_command(tree, result, global);
    return res;
}
