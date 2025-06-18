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
    if (tree->left)
        free_tree(tree->left);
    if (tree->right)
        free_tree(tree->right);
    if (tree->command_allocated && tree->command)
        free(tree->command);
    free(tree);
}
