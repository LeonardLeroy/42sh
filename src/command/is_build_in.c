/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** is_build_in.c
*/

#include "header.h"

// ADD ALIAS HERE LATER - LORAY
static enum COMMANDS is_build_in_third(char **args)
{
    if (strcmp(args[0], "marin") == 0)
        return MARIN;
    if (args[0][0] == '!')
        return EXCLAMATION;
    if (my_strcmp(args[0], "marin") == 0)
        return MARIN;
    if (my_strcmp(args[0], "42") == 0)
        return CREDITS;
    return NOTHING;
}

static enum COMMANDS is_build_in_second(char **args)
{
    if (my_strcmp(args[0], "exit") == 0)
        return EXIT;
    if (my_strlen(args[0]) <= 0)
        return ENTER;
    if (my_strcmp(args[0], "cd") == 0)
        return CD;
    if (my_strcmp(args[0], "setenv") == 0)
        return SETENV;
    if (my_strcmp(args[0], "unsetenv") == 0)
        return UNSETENV;
    if (my_strcmp(args[0], "env") == 0)
        return ENV;
    if (my_strcmp(args[0], "history") == 0)
        return HISTORY;
    if (my_strcmp(args[0], "echo") == 0)
        return ECHO_IN;
    return is_build_in_third(args);
}

enum COMMANDS is_build_in(char *buf)
{
    enum COMMANDS result;
    char **args = pass_space_and_tab(buf, " \t");

    result = is_build_in_second(args);
    my_array_free(&args);
    return result;
}
