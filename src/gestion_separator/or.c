/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** or.c
*/

#include "header.h"

int or_gestion(tree_t *tree, int *result, global_t *global)
{
    if (!tree->left->command || !tree->right->command) {
        my_puterror("Invalid null command.\n");
        return ERROR;
    }
    if (execute_tree(tree->left, result, global) == -1)
        return -1;
    if (*result == NOERROR)
        return NOERROR;
    if (execute_tree(tree->right, result, global) == -1)
        return -1;
    return NOERROR;
}
