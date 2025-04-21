/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** print_file.c
*/

#include "header.h"

int print_file(char const *file)
{
    FILE *stream;
    char buffer[MAXINPUT];

    do {
        stream = fopen(file, "r");
    } while (stream == NULL);
    while (fgets(buffer, sizeof(buffer), stream))
        mini_printf("%s", buffer);
    my_putchar('\n');
    fclose(stream);
    return 0;
}
