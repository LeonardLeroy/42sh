/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** update_left_and_right.c
*/

#include "header.h"

static void free_splitted(char ***splitted)
{
    for (int i = 0; (*splitted)[i]; i++) {
        free((*splitted)[i]);
    }
    free(*splitted);
}

static void set_child_command(tree_t *child, char *new_command)
{
    if (new_command && strlen(new_command) > 0) {
        child->command = my_strdup(new_command);
        child->command_allocated = 1;
    } else {
        child->command = NULL;
        child->command_allocated = 0;
    }
}

void update_left_and_right(tree_t *tree, const char *command, const char *sep,
    int *is_in)
{
    char **splitted = split_string(command, sep, is_in);

    if ((*is_in)) {
        free_splitted(&splitted);
        return;
    }
    tree->left = tree_init();
    set_child_command(tree->left, splitted[0]);
    tree->right = tree_init();
    set_child_command(tree->right, splitted[1]);
    free_splitted(&splitted);
}
