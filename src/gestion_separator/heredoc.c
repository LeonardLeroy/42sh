/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** heredoc.c
*/

#include "header.h"

int setup_heredoc_pipe(int *pipefd)
{
    if (pipe(pipefd) == -1)
        return ERROR;
    return NOERROR;
}

int write_to_heredoc(int *pipefd, const char *content)
{
    FILE *out = fdopen(pipefd[1], "w");

    if (!out)
        return ERROR;
    fprintf(out, "%s", content);
    fclose(out);
    return NOERROR;
}

int execute_with_heredoc_input(tree_t *tree, int *result,
    global_t *global, int *pipefd)
{
    int saved_stdin = dup(STDIN_FILENO);
    int ret;

    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    ret = execute_tree(tree->left, result, global);
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    return ret;
}

int heredoc_gestion(tree_t *tree, int *result, global_t *global)
{
    int pipefd[2];

    if (redir_handling(tree) == ERROR)
        return ERROR;
    if (setup_heredoc_pipe(pipefd) == ERROR)
        return ERROR;
    if (write_to_heredoc(pipefd, tree->right->command) == ERROR)
        return ERROR;
    return execute_with_heredoc_input(tree, result, global, pipefd);
}
