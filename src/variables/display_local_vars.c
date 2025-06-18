/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** display_local_vars.c
*/

#include "header.h"

int display_local_vars(local_var_t *head)
{
    local_var_t *current = head;

    while (current != NULL) {
        mini_printf("%s\t%s\n", current->name, current->value);
        current = current->next;
    }
    return 0;
}
