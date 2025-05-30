/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** and.c
*/

#include "header.h"

int and_gestion(tree_t *tree, int *result, Global_t *global)
{
    if (!tree->left || !tree->right || !tree->left->command
        || !tree->right->command)
        return NOERROR;
    if (execute_tree(tree->left, result, global) == -1)
        return -1;
    if (*result != NOERROR)
        return ERROR;
    if (execute_tree(tree->right, result, global) == -1)
        return -1;
    return NOERROR;
}
