/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** get_local_var.c
*/

#include "header.h"

local_var_t *find_local_var(local_var_t *head, const char *name)
{
    local_var_t *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

char *get_local_var(local_var_t *head, const char *name)
{
    local_var_t *var = find_local_var(head, name);

    return var ? var->value : NULL;
}
