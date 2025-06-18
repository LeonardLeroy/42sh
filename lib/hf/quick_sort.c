/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-organized-pierre.riss
** File description:
** quick_sort.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "help_fc.h"

linked_list_t *repeat(struct quick_sort_info* datas,
    int(*f) (linked_list_t *, void *, void *), linked_list_t *comparator,
    linked_list_t *(*cpy) (linked_list_t *))
{
    linked_list_t *temp = malloc(sizeof(linked_list_t));

    datas->pivot = (*cpy)(datas->pivot);
    if (!is_empty(datas->plus) && is_empty(datas->minus)){
        datas->pivot->next = quicksort(datas->plus, f, comparator, cpy);
        return datas->pivot;
    }
    if (is_empty(datas->plus) && !is_empty(datas->minus)){
        temp = quicksort(datas->minus, f, comparator, cpy);
        add_node(temp, datas->pivot->data);
        return temp;
    }
    if (!is_empty(datas->plus) && !is_empty(datas->minus)){
        datas->pivot->next = quicksort(datas->plus, f, comparator, cpy);
        (*temp) = (*quicksort(datas->minus, f, comparator, cpy));
        merge_linked_list(temp, datas->pivot);
        return temp;
    }
    return datas->pivot;
}

linked_list_t *quicksort(linked_list_t *begin,
    int(*f) (linked_list_t *, void *, void *),
    linked_list_t *comparator, linked_list_t *(*cpy) (linked_list_t *))
{
    struct quick_sort_info* datas = malloc(sizeof(struct quick_sort_info));

    datas->pivot = begin;
    datas->minus = instantiate_linked_list();
    datas->plus = instantiate_linked_list();
    for (linked_list_t *link = datas->pivot->next; link != NULL;
    link = link->next){
        if ((((*f)(comparator, link->data, datas->pivot->data)) == 1)){
            add_node(datas->plus, link->data);
        } else {
            add_node(datas->minus, link->data);
        }
    }
    return repeat(datas, f, comparator, cpy);
}
