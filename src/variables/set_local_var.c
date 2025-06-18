/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** set_local_var.c
*/

#include "header.h"

static local_var_t *create_local_var(const char *name, const char *value)
{
    local_var_t *new_var = malloc(sizeof(local_var_t));

    if (!new_var)
        return NULL;
    new_var->name = strdup(name);
    new_var->value = strdup(value);
    new_var->next = NULL;
    if (!new_var->name || !new_var->value) {
        free(new_var->name);
        free(new_var->value);
        free(new_var);
        return NULL;
    }
    return new_var;
}

int set_local_var(local_var_t **head, const char *name,
    const char *value)
{
    local_var_t *var = find_local_var(*head, name);
    local_var_t *new_var;

    if (var) {
        free(var->value);
        var->value = strdup(value);
        return var->value ? 0 : -1;
    } else {
        new_var = create_local_var(name, value);
        if (!new_var)
            return -1;
        new_var->next = *head;
        *head = new_var;
        return 0;
    }
}
