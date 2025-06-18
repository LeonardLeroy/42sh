/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myhunter-pierre.riss
** File description:
** free_list.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

/**
 * @brief Frees the memory allocated for a linked list and its data.
 *
 * This function traverses a linked list starting
 * from the provided node, applies a given function
 * to each element's data, and frees the memory
 * associated with each node.
 *
 * @param begin A pointer to the first node of the linked list to be freed.
 * @param f A function pointer that is applied to the data of each node.
 *          It takes a pointer to the node's data and returns an integer.
 *
 * @return void
 */
void free_list(linked_list_t *begin, int(*f) (void *))
{
    linked_list_t *link;
    linked_list_t *next_link;

    if (begin->next == NULL){
        (*f)(begin->data);
        free(begin);
        return;
    }
    next_link = begin->next->next;
    link = begin->next;
    while (next_link != NULL){
        next_link = link->next;
        (*f)(link->data);
        free(link);
        link = next_link;
    }
    (*f)(begin->data);
    free(link);
    free(begin);
}
