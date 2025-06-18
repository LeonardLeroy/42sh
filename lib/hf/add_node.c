/*
** EPITECH PROJECT, 2024
** temp_setting_up
** File description:
** add_node.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "help_fc.h"

/**
 * @brief Adds a new node with the given value at the end of a linked list.
 *
 * @param begin Pointer to the first node of the linked list.
 * @param value Pointer to the data to be stored in the new node.
 * @return 0 on success.
 */
int *add_node(linked_list_t *begin, void *value)
{
    linked_list_t *link = begin;
    linked_list_t *add;

    if (begin->data == NULL && begin->next == NULL) {
        begin->data = value;
        begin->next = NULL;
        return 0;
    }
    for (; link->next != NULL; link = link->next) {
    }
    add = malloc(sizeof(linked_list_t));
    add->data = value;
    add->next = NULL;
    link->next = add;
    return 0;
}
