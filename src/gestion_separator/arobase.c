/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** arobase.c
*/

#include "header.h"

int arobase_gestion(tree_t *tree, int *result, Global_t *global)
{
    if (tree->left && my_strlen(tree->left->command) != 0)
        if (execute_tree(tree->left, result, global) == -1)
            return -1;
    sleep(3);
    if (tree->right && my_strlen(tree->right->command) != 0)
        if (execute_tree(tree->right, result, global) == -1)
            return -1;
    return NOERROR;
}
