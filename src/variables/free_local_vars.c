/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** free_local_vars.c
*/

#include "header.h"

void free_local_vars(local_var_t **head)
{
    local_var_t *current = *head;
    local_var_t *next;

    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
    *head = NULL;
}
