/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** redir_output.c
*/

#include "header.h"

int redir_output_gestion(tree_t *tree, int *result, Global_t *global)
{
    char **args;
    int fd;
    int saved_stdout = dup(STDOUT_FILENO);
    int ret;

    if (redir_handling(tree) == ERROR)
        return ERROR;
    args = pass_space_and_tab(tree->right->command, " \t");
    fd = open(args[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        my_puterror("Error: cannot open file for writing.\n");
        return -1;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    ret = execute_tree(tree->left, result, global);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    return ret;
}
