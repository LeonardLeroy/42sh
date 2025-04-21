/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** display_path.c
*/

#include "header.h"

void display_path(int iserror)
{
    char buf[SIZE_PATH];
    char *cwd = getcwd(buf, SIZE_PATH);
    char *to_display = NULL;
    char *temp = NULL;
    char *saveptr = NULL;

    if (!cwd) {
        perror("getcwd");
        return;
    }
    temp = strtok_r(cwd, "/", &saveptr);
    while (temp != NULL) {
        to_display = temp;
        temp = strtok_r(NULL, "/", &saveptr);
    }
    mini_printf("\33[2K\r%s➜  \033[0m",
        iserror == NOERROR ? "\033[1;32m" : "\033[1;31m");
    mini_printf("\033[1;35m%s \033[1;33m✗ \033[0m", to_display);
}
