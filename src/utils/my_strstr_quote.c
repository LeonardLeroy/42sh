/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_strstr_quote.c
*/

#include "header.h"

static void handling_quote(int simple_quote, int double_quote)
{
    if (simple_quote)
        my_puterror("Unmatched '''.");
    if (double_quote)
        my_puterror("Unmatched '\"'.");
}

static int my_true_strstr(const char *str, const char *to_find, int *trouve,
    int *ij[2])
{
    int *i = ij[0];
    int *j = ij[1];

    if (str[*i] == to_find[*j]) {
        *trouve = *j == 0 ? *i : *trouve;
        (*j)++;
        if (to_find[*j] == '\0')
            return TRUE;
    } else {
        *j = 0;
        *trouve = -1;
    }
    return FALSE;
}

char *my_strstr_quote(const char *str, const char *to_find)
{
    int j = 0;
    int trouve = -1;
    int simple_quote = FALSE;
    int double_quote = FALSE;

    if (!str || !to_find || to_find[0] == '\0')
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\'' && !double_quote)
            simple_quote = !simple_quote;
        if (str[i] == '"' && !simple_quote)
            double_quote = !double_quote;
        if (simple_quote || double_quote)
            continue;
        if (my_true_strstr(str, to_find, &trouve, (int *[2]) {&i, &j}) == 1)
            return (char *) &str[trouve];
    }
    handling_quote(simple_quote, double_quote);
    return NULL;
}
