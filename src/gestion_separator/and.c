/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** and.c
*/

#include "header.h"

int and_gestion(tree_t *tree, int *result, global_t *global)
{
    if (tree->left->command && !tree->right->command) {
        my_puterror("Invalid null command.\n");
        return ERROR;
    }
    if (tree->left && tree->left->command)
        if (execute_tree(tree->left, result, global) == -1)
            return -1;
    if ((tree->left->command && *result != NOERROR) || !tree->right
        || !tree->right->command)
        return ERROR;
    if (execute_tree(tree->right, result, global) == -1)
        return -1;
    return NOERROR;
}
