/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** free_tree.c
*/

#include "header.h"

void free_tree(tree_t *tree)
{
    if (!tree)
        return;
    if (tree->command_allocated)
        free(tree->command);
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}
