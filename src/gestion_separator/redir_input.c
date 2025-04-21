/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** redir_input.c
*/

#include "header.h"

int redir_input_gestion(tree_t *tree, int *result, Global_t *global)
{
    char **args;
    int fd;
    int saved_stdin = dup(STDIN_FILENO);
    int ret;

    if (redir_handling(tree) == ERROR)
        return ERROR;
    args = pass_space_and_tab(tree->right->command, " \t");
    fd = open(args[0], O_RDONLY);
    if (fd == -1) {
        my_puterror("Error: cannot open file for reading.\n");
        return -1;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    ret = execute_tree(tree->left, result, global);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    return ret;
}
