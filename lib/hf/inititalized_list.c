/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-mytop-pierre.riss
** File description:
** inititalized_list.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

/**
 * @brief Allocates and initializes a new linked list node.
 *
 * @return
 *   A pointer to the newly created linked list node, with `data` set to NULL
 *   and `next` set to NULL.
 */
linked_list_t *instantiate_linked_list(void)
{
    linked_list_t *start = malloc(sizeof(linked_list_t));

    start->data = NULL;
    start->next = NULL;
    return start;
}
