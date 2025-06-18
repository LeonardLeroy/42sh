/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** free_jobs.c
*/

#include "header.h"

void free_jobs(linked_list_t **head)
{
    linked_list_t *current = *head;
    linked_list_t *next;

    while (current) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    *head = NULL;
}
