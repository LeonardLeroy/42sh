/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday11-pierre.riss
** File description:
** my_delete_nodes.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

int last_delete_node(linked_list_t *link,
    void *compare, int(*f) (void *, void *))
{
    if ((((*f)(link->next->data, compare)) == 1)){
        link->next = NULL;
        return 0;
    }
    if ((((*f)(link->data, compare)) == 1)){
        link->data = link->next->data;
        link->next = link->next->next;
        return 0;
    }
    return 1;
}

/**
 * @brief Removes all nodes from the list that match the given criterion.
 *
 * This function traverses the linked list and removes nodes containing data
 * that matches `compare` according to the function `f`.
 *
 * @param begin Pointer to the beginning of the linked list.
 * @param compare Value used for comparison.
 * @param f Comparison function between two elements:
 *          - The first element is the list element (`void *`).
 *          - The second element is the `compare` pointer (`void *`).
 *          The function `f` must return a value:
 *          - `1` if the elements are considered equal.
 *          - `0` if the elements are not equal.
 * @return Returns 0 if one or more nodes were removed, otherwise 1.
 */
int my_delete_nodes(linked_list_t *begin,
    void *compare, int(*f) (void *, void *))
{
    linked_list_t *link = begin;

    if (begin->next == NULL){
        if (((*f)(begin->data, compare)) == 1){
            begin->next = NULL;
            begin->data = NULL;
        }
        return 0;
    }
    while (link->next->next != NULL){
        if ((((*f)(link->data, compare)) == 1)){
            link->data = link->next->data;
            link->next = link->next->next;
        } else {
            link = link->next;
        }
    }
    return last_delete_node(link, compare, f);
}
