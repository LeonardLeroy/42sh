/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** shell.c
*/

#include "header.h"

static int process_input(global_t *global, char *INPUT, int *result)
{
    char *expanded_input = expand_aliases(global, INPUT);
    char *var_replaced_input = replace_variables(global, expanded_input);
    tree_t *tree = tree_init();

    if (!var_replaced_input) {
        if (expanded_input != INPUT)
            free(expanded_input);
        free_tree(tree);
        return ERROR;
    }
    tree->command = var_replaced_input;
    for (enum TYPES i = WORD; i < END; i++)
        parse_by_char_in_tree(tree, i);
    *result = execute_tree(tree, result, global);
    free_tree(tree);
    if (var_replaced_input != expanded_input)
        free(var_replaced_input);
    if (expanded_input != INPUT)
        free(expanded_input);
    return *result;
}

static char *decal_str(int len, int i, char *str)
{
    for (int j = len; j > i; j--)
        str[j + 1] = str[j];
    return str;
}

static char *add_separator(char *str, char target, char replace_value)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == target && (i == 0 || str[i - 1] != target) &&
            (i == len - 1 || str[i + 1] != target)) {
            str = realloc(str, sizeof(char) * (len + 2));
            str = decal_str(len, i, str);
            str[i + 1] = replace_value;
            len++;
            i++;
        }
    }
    str[len] = '\0';
    return str;
}

static int loop(global_t *global)
{
    char *INPUT = "";
    int result = NOERROR;

    while (get_command(&INPUT, result, global) != -1) {
        signal(SIGTTOU, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);
        check_finished_jobs(global);
        gestion_history(global, INPUT);
        add_separator(INPUT, '&', ';');
        result = process_input(global, INPUT, &result);
        free(INPUT);
        if (result == -1)
            break;
    }
    return result;
}

int shell(global_t *global)
{
    int result;

    enable_raw_mode(&(global->term));
    result = loop(global);
    disable_raw_mode(&(global->term));
    mini_printf("%s", isatty(STDIN_FILENO) ? "exit\n" : "");
    return result;
}
