# 42sh

## Project Overview

**42sh** is a full-featured Unix shell developed in C as part of an **Epitech** group project. It is inspired by the behavior and syntax of the `tcsh` shell. The focus is on **stability**, **job control**, and implementing **advanced shell features** commonly used in daily Unix workflows.

---

## Compilation

- Binary name: `42sh`
- Language: C
- Build system: `Makefile` with standard rules:
    - make
    - make clean
    - make fclean
    - make re
Only standard C library functions and `ncurses` are allowed.

---

## Features

| Feature              | Commands / Syntax             | Description                                 |
|----------------------|-------------------------------|---------------------------------------------|
| Inhibitors           | `' '`, `\`                    | Escape special characters                   |
| Globbing             | `*`, `?`, `[ ]`               | Pattern matching (wildcards)                |
| Job Control          | `&`, `fg`, `bg`               | Background execution and job switching      |
| Command Substitution | `` `command` ``               | Execute a command and use its output        |
| Parentheses          | `(command)`                   | Run commands in subshells                   |
| Variables            | `$VAR`, `set`, `unset`        | Local and environment variable management   |
| Special Variables    | `$term`, `$precmd`, `$cwd`... | Shell state and behavior customization      |
| History              | `!`, `!!`, `!42`, etc.        | Command history and repetition              |
| Aliases              | `alias ll 'ls -l'`            | Custom command shortcuts                    |
| Line Editing         | Auto-completion, multi-line   | Interactive line input, dynamic keybinding  |
| Basic Scripting      | `. script.sh` (limited)       | Execute simple scripts (basic support)      |

---

## Bonus

- Advanced scripting
- Logical operators (`&&`, `||`)
- Complex piping
- Advanced redirections (`>>`, `2>`, etc.)
- Debug or verbose mode
- Colorized output
- A Marin Kitagawa buidin

---

## Authors

Project developed by a team of Epitech students.
