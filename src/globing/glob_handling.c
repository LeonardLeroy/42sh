/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** glob_handling.c
*/

#include "header.h"

int glob_handling(char ***args, int idx)
{
    int err = 0;
    char **finds_args = NULL;
    char *curr_arg = (*args)[idx];

    if (is_glob(curr_arg)) {
        err = globing(curr_arg, &finds_args);
        if (err != 0 && err != GLOB_NOMATCH) {
            my_puterror("Glob error\n");
            return err;
        }
        if (err != GLOB_NOMATCH)
            (*args) = insert_strarray_in_strarray(*args, finds_args, idx);
    }
    return NOERROR;
}
