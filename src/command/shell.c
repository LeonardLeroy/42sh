/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** shell.c
*/

#include "header.h"

static int loop(Global_t *global)
{
    char *INPUT = NULL;
    int result = NOERROR;
    tree_t *tree;

    while (get_command(&INPUT, result, global) != -1) {
        gestion_history(global, INPUT);
        tree = tree_init();
        tree->command = INPUT;
        for (enum TYPES i = WORD; i < END; i++)
            parse_by_char_in_tree(tree, i);
        result = execute_tree(tree, &result, global);
        free_tree(tree);
        free(INPUT);
        if (result == -1)
            break;
    }
    return result;
}

int shell(Global_t *global)
{
    int result;
    struct termios term;

    enable_raw_mode(&term);
    result = loop(global);
    disable_raw_mode(&term);
    mini_printf("%s", isatty(STDIN_FILENO) ? "exit\n" : "");
    return result;
}
