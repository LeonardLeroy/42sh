/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** glob_transformation.c
*/

#include "header.h"

int glob_transformation(char ***args)
{
    ssize_t err = 0;

    for (size_t i = 0; (*args)[i]; i++) {
        err = glob_handling(args, i);
        if (err != 0)
            return err;
    }
    return NOERROR;
}
