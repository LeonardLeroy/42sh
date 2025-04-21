/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** raw_mode.c
*/

#include "header.h"

void enable_raw_mode(struct termios *term)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, term);
    raw = *term;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disable_raw_mode(struct termios *term)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, term);
}
