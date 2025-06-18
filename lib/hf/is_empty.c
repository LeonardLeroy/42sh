/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.riss
** File description:
** is_empty.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

/**
 * @brief Checks if the linked list is empty.
 *
 * @param begin Pointer to the first node of the linked list.
 *
 * @returns
 *   - 1 if the list is empty
 * @returns
 *   - 0 if the list is not empty.
 */
int is_empty(linked_list_t *begin)
{
    if (begin->data == NULL && begin->next == NULL)
        return 1;
    return 0;
}
