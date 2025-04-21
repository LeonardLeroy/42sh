/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** exclamation.c
*/

#include "header.h"

static int execute_one_line(Global_t *global, char *INPUT)
{
    int result = NOERROR;
    tree_t *tree;

    gestion_history(global, INPUT);
    tree = tree_init();
    tree->command = INPUT;
    for (enum TYPES i = WORD; i < END; i++)
        parse_by_char_in_tree(tree, i);
    result = execute_tree(tree, &result, global);
    free_tree(tree);
    free(INPUT);
    return result;
}

int exclamation_command(Global_t *global, char *input)
{
    size_t len = my_strlen(input) - 1;
    char *new_input = NULL;

    if (len <= 0)
        return ERROR;
    input = &input[1];
    for (int i = global->size_history - 2; i >= 0; i--) {
        if (strncmp(global->history[i], input, len) == 0
            || strcmp(input, "!") == 0) {
            new_input = my_strdup(global->history[i]);
            break;
        }
    }
    if (!new_input)
        return ERROR;
    mini_printf("%s\n", new_input);
    return execute_one_line(global, new_input);
}
