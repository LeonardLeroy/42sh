/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** free_aliases.c
*/

#include "header.h"

void free_aliases(alias_t **head)
{
    alias_t *current = *head;
    alias_t *next;

    while (current) {
        next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    *head = NULL;
}
