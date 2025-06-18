/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** test_signal.c
*/

#include "header.h"

static void is_cord_dump(int status)
{
    if (WCOREDUMP(status))
        my_puterror(" (core dumped)");
    my_puterror("\n");
}

static int handle_signal(int status)
{
    int result = 0;

    if (WTERMSIG(status) == SIGSEGV) {
        my_puterror("Segmentation fault");
        is_cord_dump(status);
        result = 128 + SIGSEGV;
    } else if (WTERMSIG(status) == SIGFPE) {
        my_puterror("Floating exception");
        is_cord_dump(status);
        result = 128 + SIGFPE;
    }
    return result;
}

int test_signal(int status)
{
    if (WIFSIGNALED(status)) {
        return handle_signal(status);
    }
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return ERROR;
}
