/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** unset_local_var.c
*/

#include "header.h"

int unset_local_var(local_var_t **head, const char *name)
{
    local_var_t *current = *head;
    local_var_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) != 0) {
            prev = current;
            current = current->next;
            continue;
        }
        if (prev == NULL)
            *head = current->next;
        else
            prev->next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        return 0;
    }
    return -1;
}
