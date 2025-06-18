/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday11-pierre.riss
** File description:
** my_rev_list.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

linked_list_t *my_rev_list(linked_list_t *begin)
{
    linked_list_t *nouveau_link;
    linked_list_t *save_link;
    linked_list_t *link = begin;

    save_link = malloc(sizeof(linked_list_t));
    save_link->next = NULL;
    save_link->data = link->data;
    link = link->next;
    for (; link != NULL; link = link->next){
        nouveau_link = malloc(sizeof(linked_list_t));
        nouveau_link->data = link->data;
        nouveau_link->next = save_link;
        save_link = nouveau_link;
    }
    if (begin->next == NULL)
        return begin;
    return nouveau_link;
}
