/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** heredoc.c
*/

#include "header.h"

int heredoc_gestion(tree_t *tree, int *result, Global_t *global)
{
    char **args;
    int pipefd[2];
    int saved_stdin;
    int ret;

    if (redir_handling(tree) == ERROR)
        return ERROR;
    args = pass_space_and_tab(tree->right->command, " \t");
    if (pipe(pipefd) == -1)
        return -1;
    fprintf(fdopen(pipefd[1], "wc"), "%s\n", args[0]);
    close(pipefd[1]);
    saved_stdin = dup(STDIN_FILENO);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    ret = execute_tree(tree->left, result, global);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    return ret;
}
