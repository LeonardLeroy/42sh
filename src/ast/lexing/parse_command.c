/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_command.c
*/

#include "header.h"

void parse_command(char *INPUT)
{
    tree_t *tree = tree_init();

    tree->command = INPUT;
    for (enum TYPES i = WORD; i < END; i++)
        parse_by_char_in_tree(tree, i);
    free_tree(tree);
}
