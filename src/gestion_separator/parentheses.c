/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parentheses.c
*/

#include "header.h"

static int is_rounded(char *buffer, tree_t *tree)
{
    return sscanf(tree->command, "%*[^()](%[^)])%*[^()]", buffer) == 1
        || sscanf(tree->command, "(%[^)])", buffer) == 1;
}

int parentheses_block(tree_t *tree, int *result, global_t *global)
{
    char buffer[1024];
    int status;
    pid_t pid = fork();

    if (pid < 0)
        return ERROR;
    if (pid == 0) {
        if (is_rounded(buffer, tree))
            tree->command = my_strdup(buffer);
        tree->type = WORD;
        for (enum TYPES i = WORD; i < END; i++)
            parse_by_char_in_tree(tree, i);
        *result = execute_tree(tree, result, global);
        exit(*result);
    }
    do {
        wait(&status);
        *result = test_signal(status);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    return NOERROR;
}
