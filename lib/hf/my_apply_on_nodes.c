/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday11-pierre.riss
** File description:
** : my_apply_on_nodes.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

/**
 * @brief Applies function f to each node's data in the linked list.
 *
 * @begin: Pointer to the first node of the linked list.
 * @f: Function pointer that takes a void pointer
 * (node data) and returns an int.
 *
 * Return:
 *   - 0 if the function was applied to all nodes successfully.
 *   - -1 if the linked list is empty.
 */
int my_apply_on_nodes(linked_list_t *begin, int(*f) (void *))
{
    if (is_empty(begin))
        return -1;
    for (linked_list_t *link = begin; link != NULL; link = link->next){
        (*f)(link->data);
    }
    return 0;
}
