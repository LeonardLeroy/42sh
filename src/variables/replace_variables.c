/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** replace_variables.c
*/

#include "header.h"

static char *extract_variable_name(char *str, int start_pos)
{
    int j = start_pos;

    while (str[j] && (isalnum(str[j]) || str[j] == '_')) {
        j++;
    }
    return strndup(&str[start_pos], j - start_pos);
}

static int get_variable_value(global_t *global, char *var_name,
    char **value)
{
    *value = get_local_var(global->local_vars, var_name);
    if (!*value)
        *value = my_getenv(global, var_name);
    return (*value != NULL);
}

static int replace_variable_reference(replace_state_t *state, char *var_value,
    int var_end_pos)
{
    size_t var_ref_len = (var_end_pos - state->i);
    size_t var_val_len = strlen(var_value);
    size_t new_size = state->result_size - var_ref_len + var_val_len;
    char *new_result = malloc(new_size);

    if (!new_result)
        return ERROR;
    strncpy(new_result, state->result, state->i);
    new_result[state->i] = '\0';
    strcat(new_result, var_value);
    strcat(new_result, &state->result[var_end_pos]);
    free(state->result);
    state->result = new_result;
    state->result_size = new_size;
    state->i += var_val_len - 1;
    return NOERROR;
}

static int process_variable_reference(global_t *global, replace_state_t *state,
    int var_end_pos)
{
    char *var_name = extract_variable_name(state->result, state->i + 1);
    char *var_value = NULL;
    int result = NOERROR;
    size_t var_ref_len;

    if (!var_name)
        return ERROR;
    if (get_variable_value(global, var_name, &var_value)) {
        result = replace_variable_reference(state, var_value, var_end_pos);
    } else {
        var_ref_len = (var_end_pos - state->i);
        memmove(&state->result[state->i], &state->result[var_end_pos],
            strlen(&state->result[var_end_pos]) + 1);
        state->result_size -= var_ref_len;
        state->i--;
    }
    free(var_name);
    return result;
}

static int handle_variable_replacement(global_t *global,
    replace_state_t *state)
{
    int var_end_pos = state->i + 1;

    while (state->result[var_end_pos] &&
        (isalnum(state->result[var_end_pos]) ||
        state->result[var_end_pos] == '_'))
        var_end_pos++;
    return process_variable_reference(global, state, var_end_pos);
}

char *replace_variables(global_t *global, char const *input)
{
    replace_state_t state = {0};

    if (!input)
        return NULL;
    state.result = strdup(input);
    if (!state.result)
        return NULL;
    state.result_size = strlen(input) + 1;
    for (state.i = 0; state.result[state.i]; state.i++) {
        if (!(state.result[state.i] == VAR_DETECTOR &&
            state.result[state.i + 1] &&
            (isalpha(state.result[state.i + 1]) ||
            state.result[state.i + 1] == '_')))
            continue;
        if (handle_variable_replacement(global, &state) != NOERROR) {
            free(state.result);
            return NULL;
        }
    }
    return state.result;
}
