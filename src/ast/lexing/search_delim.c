/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** search_delim.c
*/

#include "header.h"

static void count_types(quotetype_t *types, char c)
{
    switch (c) {
        case '(':
            types->parentheses++;
            break;
        case ')':
            types->parentheses--;
            break;
        case '\'':
            types->simple_quote = !types->simple_quote;
            break;
        case '"':
            types->double_quote = !types->double_quote;
            break;
        case '`':
            types->chelou_quote = !types->chelou_quote;
            break;
    }
}

int search_delim(const char *str, const char *delimiter)
{
    int len = my_strlen(delimiter);
    quotetype_t types = {0, 0, 0, 0};

    for (int i = 0; str[i] != '\0'; i++) {
        count_types(&types, str[i]);
        if (strncmp(&str[i], delimiter, len) == 0
            && (!types.parentheses && !types.simple_quote
                && !types.double_quote && !types.chelou_quote)) {
            return i;
        }
    }
    return -1;
}

// static int handle_backtick(tree_t *tree)
// {
//     char *cmd;
//     tree_t *new_node;
//     int result;

//     result = extract_backtick_cmd(tree->command, &cmd);
//     if (result <= 0)
//         return (result);
//     new_node = tree_init();
//     tree->left = new_node;
//     new_node->command = cmd;
//     tree->command = my_strdup("`");
//     tree->type = BACKSTICKS;
//     free(cmd);
//     return (1);
// }

// static void handle_separator(tree_t *tree, const char *sep, enum TYPES type)
// {
//     int is_in = FALSE;

//     if (tree->type != WORD)
//         return;
//     if (!my_strstr_quote(tree->command, sep))
//         return;
//     update_left_and_right(tree, tree->command, sep, &is_in);
//     free(tree->command);
//     tree->command = my_strdup(sep);
//     tree->type = type;
// }

// static int extract_backtick_cmd(const char *line, char **cmd_out)
// {
//     char *start;
//     char *end;
//     size_t cmd_len;

//     start = strchr(line, '`');
//     if (!start)
//         return (0);
//     end = strchr(start + 1, '`');
//     if (!end) {
//         fprintf(stderr,
//             "Erreur : Backtick non terminé dans la
//             commande skill issue.\n");
//         return (-1);
//     }
//     cmd_len = end - start - 1;
//     *cmd_out = my_strndup(start + 1, cmd_len);
//     return (1);
// }
