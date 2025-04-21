/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** print_tree.c
*/

#include "header.h"

void print_tree(tree_t *tree, int occu)
{
    char spaces[occu * 2];

    if (!tree)
        return;
    for (int i = 0; i < (occu * 2); i++)
        spaces[i] = ' ';
    spaces[occu * 2] = '\0';
    mini_printf("%s↳ %s\n", spaces, tree->command);
    print_tree(tree->left, occu + 1);
    print_tree(tree->right, occu + 1);
}
