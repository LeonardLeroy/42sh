/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** is_build_in.c
*/

#include "header.h"

const char *builtins[] = {"exit", "cd", "setenv", "unsetenv", "env", "",
    "history", "echo", "marin", "lucy", "doom", "!", "alias", "unalias",
    "credits", "set", "unset", "foreach", "which", "where", "if", "else",
    "repeat", "jobs", "fg", "bg", "copilot"};

enum COMMANDS is_build_in(char *buf)
{
    char **words;
    char *first_word;

    if (!buf || !buf[0])
        return ENTER;
    words = pass_space_and_tab(buf, " \t");
    if (!words || !words[0])
        return ENTER;
    first_word = words[0];
    for (int i = 0; i < (int) (sizeof(builtins) / sizeof(builtins[0])); i++) {
        if (strcmp(first_word, builtins[i]) == 0) {
            my_array_free(&words);
            return (enum COMMANDS) i;
        }
        if (first_word[0] == '!')
            return EXCLAMATION;
    }
    my_array_free(&words);
    return NOTHING;
}
