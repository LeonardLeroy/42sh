/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** redir_error_handling.c
*/

#include "header.h"

int redir_handling(tree_t *tree)
{
    if ((!tree->right || my_strlen(tree->right->command) == 0 ||
        tree->right->command == NULL ||
        my_strcmp(tree->right->command, "<<") == 0) ||
        (!tree->left || tree->left->command == NULL ||
        my_strcmp(tree->left->command, "<<") == 0)) {
        my_puterror("Missing name for redirect.\n");
        return ERROR;
    }
    if (!tree->left || my_strlen(tree->left->command) == 0) {
        my_puterror("Invalid null command.\n");
        return ERROR;
    }
    return NOERROR;
}
