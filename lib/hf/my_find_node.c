/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday11-pierre.riss
** File description:
** my_find_node.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "help_fc.h"

/**
 * @brief Finds a node in a linked list based on a comparison function.
 * @param begin Pointer to the beginning of the linked list.
 * @param cmp Pointer to the reference data used for comparison.
 * @param f Function pointer to a comparison function
 * of the form `int f(void *node_data, void *cmp_data)`,
 * which returns 1 if a match is found.
 * @return Pointer to the matching node's data, or NULL if no match is found.
 */
void *my_find_node(linked_list_t *begin, void *cmp_data,
    int (*f)(void *, void *))
{
    if (is_empty(begin))
        return NULL;
    for (linked_list_t *link = begin; link != NULL; link = link->next) {
        if (((*f)(link->data, cmp_data)) == 1) {
            return link->data;
        }
    }
    return NULL;
}
