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

int test_signal(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            my_puterror("Segmentation fault");
            is_cord_dump(status);
            return 128 + SIGSEGV;
        }
    }
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return ERROR;
}
