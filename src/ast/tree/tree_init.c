/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** tree_init.c
*/

#include "header.h"

tree_t *tree_init(void)
{
    tree_t *tree = emalloc(sizeof(tree_t));

    tree->command = NULL;
    tree->command_allocated = 0;
    tree->type = WORD;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}
