/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** execute_command.c
*/

#include "header.h"

static void basile_handling(char *used)
{
    my_puterror(used);
    my_puterror(": Exec format error. Binary file not executable.\n");
}

static void permission_denied(char *used)
{
    my_puterror(used);
    my_puterror(": Permission denied.\n");
}

static int process_command(char **argv, int i, Global_t *global,
    CommandData_t *cmd_data)
{
    cmd_data->processed_command = handle_inhibitions(argv[i]);
    cmd_data->processed_command =
        handle_backticks(cmd_data->processed_command);
    cmd_data->resolved_path =
        resolve_command_path(global, cmd_data->processed_command);
    cmd_data->used = cmd_data->processed_command;
    return execve(cmd_data->resolved_path, &argv[i], global->env);
}

static int handle_execution_error(char *used)
{
    strtok(used, " ");
    if (errno == ENOEXEC) {
        basile_handling(used);
        return ERROR;
    }
    if (errno == EACCES) {
        permission_denied(used);
        return ERROR;
    }
    my_puterror(used);
    my_puterror(": Command not found.\n");
    return ERROR;
}

int execute_command(char **argv, int i, Global_t *global)
{
    CommandData_t cmd_data;
    int result;

    result = process_command(argv, i, global, &cmd_data);
    if (result < 0)
        return handle_execution_error(cmd_data.used);
    return NOERROR;
}
