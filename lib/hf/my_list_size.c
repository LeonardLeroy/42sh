/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday11-pierre.riss
** File description:
** my_list_size.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

/**
 * @brief count number elements of the list
 *
 * @param begin Pointer to the beginning of the linked list.
 * @return The len of the list
 */
int my_list_size(linked_list_t *begin)
{
    int i = 0;

    if (is_empty(begin))
        return 0;
    for (linked_list_t *link = begin; link != NULL;
        link = link->next) {
        i++;
    }
    return i;
}
