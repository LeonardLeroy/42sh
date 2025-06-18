/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** buildin_copilot.c
*/

#include "header.h"

int buildin_copilot(global_t *global)
{
    disable_raw_mode(&(global->term));
    if (system("./bonus/copilot.py") <= 0)
        return ERROR;
    enable_raw_mode(&(global->term));
    return NOERROR;
}
