/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** handle_command.c
*/

#include "header.h"

static int execute_tree_next(tree_t *tree, int *result, global_t *global)
{
    if (my_strcmp(tree->command, "@") == 0)
        return arobase_gestion(tree, result, global);
    if (tree->type == PARENTHESES)
        return parentheses_block(tree, result, global);
    return execute_one_command(tree->command, result, global);
}

static int check_redir_syntax(tree_t *tree)
{
    if ((my_strcmp(tree->command, "<<") == 0 ||
        my_strcmp(tree->command, "<") == 0 ||
        my_strcmp(tree->command, ">") == 0 ||
        my_strcmp(tree->command, ">>") == 0) &&
        (!tree->right || !tree->right->command ||
            my_strlen(tree->right->command) == 0)) {
        my_puterror("Missing name for redirect.\n");
        return ERROR;
    }
    return NOERROR;
}

int handle_command(tree_t *tree, int *result, global_t *global)
{
    if (check_redir_syntax(tree) == ERROR)
        return ERROR;
    if (my_strcmp(tree->command, ";") == 0)
        return semi_colon_gestion(tree, result, global);
    if (my_strcmp(tree->command, "|") == 0)
        return pipe_gestion(tree, result, global);
    if (my_strcmp(tree->command, "<") == 0)
        return redir_input_gestion(tree, result, global);
    if (my_strcmp(tree->command, ">") == 0)
        return redir_output_gestion(tree, result, global);
    if (my_strcmp(tree->command, "<<") == 0)
        return heredoc_gestion(tree, result, global);
    if (my_strcmp(tree->command, ">>") == 0)
        return redir_append_gestion(tree, result, global);
    if (my_strcmp(tree->command, "&&") == 0)
        return and_gestion(tree, result, global);
    if (my_strcmp(tree->command, "||") == 0)
        return or_gestion(tree, result, global);
    return execute_tree_next(tree, result, global);
}
