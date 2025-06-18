/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.riss
** File description:
** merge_linked_list.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

int merge_linked_list(linked_list_t *begin, linked_list_t *second_one)
{
    linked_list_t *link = begin;

    if (is_empty(begin))
        return -1;
    for (; link->next != NULL; link = link->next){
    }
    link->next = second_one;
    return 0;
}
