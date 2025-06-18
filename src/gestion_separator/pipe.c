/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** pipe.c
*/

#include "header.h"

static int pipe_left_gestion(tree_t *tree, int *result, global_t *global,
    int pipefd[2])
{
    int saved_stdout;

    close(pipefd[0]);
    saved_stdout = dup(STDOUT_FILENO);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    if (execute_tree(tree->left, result, global) == -1) {
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);
        exit(ERROR);
    }
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    return NOERROR;
}

static int is_pipe_solo(tree_t *tree)
{
    if (!tree->left || !tree->left->command
        || my_strlen(tree->left->command) == 0) {
        my_puterror("Invalid null command.\n");
        return TRUE;
    }
    if (!tree->right || !tree->right->command
        || my_strlen(tree->right->command) == 0) {
        my_puterror("Invalid null command.\n");
        return TRUE;
    }
    return FALSE;
}

int pipe_gestion(tree_t *tree, int *result, global_t *global)
{
    int pipefd[2];
    pid_t pid;
    int status;

    if (is_pipe_solo(tree) || pipe(pipefd) == -1)
        return ERROR;
    pid = fork();
    if (pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        if (execute_tree(tree->right, result, global) == -1)
            exit(ERROR);
        exit(NOERROR);
    } else {
        pipe_left_gestion(tree, result, global, pipefd);
        waitpid(pid, &status, 0);
        *result = test_signal(status);
    }
    return NOERROR;
}
