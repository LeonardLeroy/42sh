/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_by_char_in_tree.c
*/

#include "header.h"

const char *CHAR_TYPE[] = {NULL, "`", ";", "||", ">>", "<<", ">", "<", "&&",
    "|", "@"};

static void update_is_in(tree_t *tree, char *LINE)
{
    tree->command = my_strdup(LINE);
    if (my_strstr(LINE, "(") || my_strstr(LINE, ")"))
        tree->type = PARENTHESES;
    else
        tree->type = QUOTES;
}

void parse_by_char_in_tree(tree_t *tree, enum TYPES type)
{
    char *LINE = tree->command;
    const char *sep = CHAR_TYPE[type];
    int is_in;

    if (tree->type == WORD && my_strstr(LINE, sep)) {
        is_in = FALSE;
        update_left_and_right(tree, LINE, sep, &is_in);
        if (is_in) {
            update_is_in(tree, LINE);
        } else {
            tree->command = (char *)sep;
            tree->command_allocated = 0;
            tree->type = type;
        }
    }
    if (tree->left)
        parse_by_char_in_tree(tree->left, type);
    if (tree->right)
        parse_by_char_in_tree(tree->right, type);
}
