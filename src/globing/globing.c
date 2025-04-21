/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-42sh-leonard.leroy
** File description:
** globing.c
*/

#include "header.h"

int globing(char *arg, char ***finds)
{
    glob_t glob_result;
    ssize_t status = glob(arg, GLOB_NOCHECK, NULL, &glob_result);

    if (status != 0)
        return status;
    *finds = malloc((glob_result.gl_pathc + 1) * sizeof(char *));
    if (*finds == NULL) {
        globfree(&glob_result);
        return -1;
    }
    for (size_t i = 0; i < glob_result.gl_pathc; i++) {
        (*finds)[i] = strdup(glob_result.gl_pathv[i]);
        if ((*finds)[i] == NULL)
            return -1;
    }
    (*finds)[glob_result.gl_pathc] = NULL;
    globfree(&glob_result);
    return NOERROR;
}
