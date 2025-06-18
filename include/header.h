/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** header.h
*/

#ifndef HEADER
    #define HEADER

///////////////////////////////////////////////////////////////////////////////
/// INCLUDES
///////////////////////////////////////////////////////////////////////////////

    #include "help_fc.h"
// lib C
    #include <assert.h>
    #include <ctype.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <glob.h>
    #include <limits.h>
    #include <setjmp.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <unistd.h>
// hassoul
    #include <termios.h>
// ncurses
    #include <ncurses.h>
// others authorized in minishell2
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/wait.h>
// meth
    #include <math.h>

///////////////////////////////////////////////////////////////////////////////
/// VALUES
///////////////////////////////////////////////////////////////////////////////

    #define SIZE_PATH 516
    #define NB_ARGS 64
    #define MAX_PATH 512

    #define BACKSTICKS_ERROR -1
    #define MAXINPUT 2048

    #define TOO_MANY_ARGS 0
    #define NO_DIRECTORY 1
    #define NOT_A_DIRECTORY 2
    #define GLOBINGS_CHARS "*?[]"
    #define VAR_DETECTOR '$'

    #define ANSI_COLOR_GRAY "\033[90m"
    #define ANSI_COLOR_RESET "\033[0m"

    #define MAX_ALIAS_ITERATIONS 100
    #define MAX_VISITED_ALIASES 100

    #define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin"

    #define UNUSED __attribute__((unused))

extern const char *builtins[];

///////////////////////////////////////////////////////////////////////////////
/// COMMANDS
///////////////////////////////////////////////////////////////////////////////

enum COMMANDS {
    NOTHING = -1,
    EXIT,
    CD,
    SETENV,
    UNSETENV,
    ENV,
    ENTER,
    HISTORY,
    ECHO_IN,
    MARIN,
    LUCY,
    DOOM,
    EXCLAMATION,
    ALIAS,
    UNALIAS,
    CREDITS,
    SET,
    UNSET,
    FOREACH,
    WHICH,
    WHERE,
    IF,
    ELSE,
    REPEAT,
    JOBS,
    FG,
    BG,
    COPILOT
};

enum TYPES {
    WORD = 0,
    SEMI_COLON,
    OR,
    DOUBLE_REDIROUT,
    DOUBLE_REDIRIN,
    REDIR_OUT,
    REDIR_IN,
    AND,
    PIPE,
    AROBASE,
    END,
    PARENTHESES,
    QUOTES
};

enum JOBS_STATE {
    RUNNING,
    SUSPENDED,
    TERMINATED,
    DONE
};

///////////////////////////////////////////////////////////////////////////////
/// STRUCTS
///////////////////////////////////////////////////////////////////////////////

typedef struct StringWithDel {
    char *str;
    char *delimiters;
} StringWithDel_t;

typedef struct {
    char *buffer;
    int *pos;
    char **suggestion;
} InputContext_t;

typedef struct {
    char *result;
    size_t result_size;
    int i;
} replace_state_t;

typedef struct alias_s {
    char *key;
    char *value;
    struct alias_s *next;
} alias_t;

typedef struct local_var_s {
    char *name;
    char *value;
    struct local_var_s *next;
} local_var_t;

typedef struct Global {
    char **env;
    int size_env;
    char **history;
    int size_history;
    int index;
    int size_prompt;
    struct termios term;
    alias_t *aliases;
    local_var_t *local_vars;
    pid_t last_process;
    pid_t prev_last_process;
    linked_list_t *jobs_list;
} global_t;

typedef struct process_alias_s {
    char **expanded_ptr;
    char **visited;
    int *visited_count;
    const char *first_word;
} process_alias_t;

typedef struct tree_s {
    char *command;
    int command_allocated;
    enum TYPES type;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

typedef struct {
    char *processed_command;
    char *resolved_path;
    char *used;
} CommandData_t;

typedef struct {
    int parentheses;
    int simple_quote;
    int double_quote;
    int chelou_quote;
} quotetype_t;

typedef struct jobs {
    int id;
    pid_t pid;
    char **command;
    enum JOBS_STATE state;
    int is_notify;
} jobs_t;

///////////////////////////////////////////////////////////////////////////////
/// testing
///////////////////////////////////////////////////////////////////////////////

#ifdef ENV_DEV
    #define PRI(format, ...) mini_printf(format "\n", ##__VA_ARGS__)
    #define DEBUG(str, ...) PRI("%s.%d:"str, __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DEBUG(...)
#endif

///////////////////////////////////////////////////////////////////////////////
/// lexing
///////////////////////////////////////////////////////////////////////////////

void parse_by_char_in_tree(tree_t *tree, enum TYPES type);
void parse_command(char *INPUT);
int search_delim(const char *str, const char *delimiter);
char **split_string(const char *str, const char *delimiter, int *is_in);
void update_left_and_right(tree_t *tree, const char *command, const char *sep,
    int *is_in);

///////////////////////////////////////////////////////////////////////////////
/// tree
///////////////////////////////////////////////////////////////////////////////

int execute_tree(tree_t *tree, int *result, global_t *global);
void free_tree(tree_t *tree);
int handle_command(tree_t *tree, int *result, global_t *global);
void print_tree(tree_t *tree, int occu);
tree_t *tree_init(void);

///////////////////////////////////////////////////////////////////////////////
/// array
///////////////////////////////////////////////////////////////////////////////

char **insert_strarray_in_strarray(char **dest, char **src, size_t index);
char **my_array_dup(char **array, int size);
int my_array_len(char **array);
char **my_env_array_dup(char **array, int size);
void my_array_free(char ***array);

///////////////////////////////////////////////////////////////////////////////
/// build_in
///////////////////////////////////////////////////////////////////////////////

int buildin_copilot(global_t *global);
int cd_command(char *input, global_t *global);
int echo_command(char *input, global_t *global, int *re);
int env_command(global_t *global);
int exclamation_command(global_t *global, char *input);
int history_command(global_t *global);
int setenv_command(char *input, global_t *global);
char *take_after_build_in(char *delimiter, char *str);
int unsetenv_command(char *input, global_t *global);
int alias_command(global_t *global, char *input);
void add_alias(global_t *global, char *key, char *value);
int unalias_command(global_t *global, char *input);
char *expand_aliases(global_t *global, char *input);
void free_aliases(alias_t **head);
// scripting
int else_command(global_t *global);
int foreach_command(global_t *global);
int if_command(global_t *global);
int repeat_command(global_t *global);
int where_command(global_t *global);
int which_command(global_t *global);

///////////////////////////////////////////////////////////////////////////////
/// local variables
///////////////////////////////////////////////////////////////////////////////

local_var_t *find_local_var(local_var_t *head, const char *name);
int set_local_var(local_var_t **head, const char *name, const char *value);
char *get_local_var(local_var_t *head, const char *name);
int unset_local_var(local_var_t **head, const char *name);
void free_local_vars(local_var_t **head);
int display_local_vars(local_var_t *head);
char *replace_variables(global_t *global, const char *input);
int set_command(global_t *global, char *input);
int unset_command(global_t *global, char *input);

///////////////////////////////////////////////////////////////////////////////
/// command
///////////////////////////////////////////////////////////////////////////////

void display_path(int iserror);
int execute_one_command(char *INPUT, int *result, global_t *global);
int get_command(char **input, int iserror, global_t *global);
void gestion_history(global_t *global, char *arg);
enum COMMANDS is_build_in(char *buf);
int shell(global_t *global);

///////////////////////////////////////////////////////////////////////////////
/// env
///////////////////////////////////////////////////////////////////////////////

char *my_getenv(global_t *global, char *name);
char **my_setenv(global_t *global, char *name, char *value);
void my_unsetenv(global_t *global, char *name);

///////////////////////////////////////////////////////////////////////////////
/// execute
///////////////////////////////////////////////////////////////////////////////

int execute_command(char **argv, int i, global_t *global);
int execute(char *buf, global_t *global, pid_t pid);
char *resolve_command_path(global_t *global, const char *command);
int test_signal(int status);

///////////////////////////////////////////////////////////////////////////////
/// gestion_separator
///////////////////////////////////////////////////////////////////////////////

int and_gestion(tree_t *tree, int *result, global_t *global);
int arobase_gestion(tree_t *tree, int *result, global_t *global);
char *handle_backticks(char *input);
int heredoc_gestion(tree_t *tree, int *result, global_t *global);
char *handle_inhibitions(char *input);
int or_gestion(tree_t *tree, int *result, global_t *global);
int parentheses_block(tree_t *tree, int *result, global_t *global);
int pipe_gestion(tree_t *tree, int *result, global_t *global);
int redir_append_gestion(tree_t *tree, int *result, global_t *global);
int redir_handling(tree_t *tree);
int redir_input_gestion(tree_t *tree, int *result, global_t *global);
int redir_output_gestion(tree_t *tree, int *result, global_t *global);
int semi_colon_gestion(tree_t *tree, int *result, global_t *global);

///////////////////////////////////////////////////////////////////////////////
/// globing
///////////////////////////////////////////////////////////////////////////////

int glob_handling(char ***args, int idx);
int glob_transformation(char ***args);
int is_glob(char *str);
int globing(char *arg, char ***finds);

///////////////////////////////////////////////////////////////////////////////
/// key_gestion
///////////////////////////////////////////////////////////////////////////////

void key_gestion_arrow(global_t *global, char *buffer, int *pos);
void key_gestion_backspace(int *pos, global_t *global, char *buffer);
void key_gestion_a(int *pos);
void key_gestion_e(global_t *global, int *pos);
void key_gestion_k(global_t *global, int *pos, char *buffer);
void key_gestion_u(global_t *global, int *pos, char *buffer);
int key_gestion_enter(char *buffer, global_t *global, int *pos);
void key_gestion(char c, int *pos, char *buffer, global_t *global);
void no_key_gestion(int *pos, char *buffer, char c, global_t *global);
int key_gestion_tab(char *suggestion, char *buffer, int *pos,
    global_t *global);

///////////////////////////////////////////////////////////////////////////////
/// pass
///////////////////////////////////////////////////////////////////////////////

int count_words(char *str, char *delimiters);
char *extract_word(const char *str, int *index, char *delimiters);
char **pass_space_and_tab(char *str, char *delimiters);
void process_next_token(char **words, StringWithDel_t *swd, int *index,
    int *word_index);

///////////////////////////////////////////////////////////////////////////////
/// termios
///////////////////////////////////////////////////////////////////////////////

void enable_raw_mode(struct termios *term);
void disable_raw_mode(struct termios *term);
void display_with_suggestion(const char *buffer, const char *suggestion,
    int pos);
int read_input(char *buffer, global_t *global);
void gestion_multi_lines(char **input, global_t *global);

///////////////////////////////////////////////////////////////////////////////
/// suggestion
///////////////////////////////////////////////////////////////////////////////

void display_with_suggestion(const char *buffer, const char *suggestion,
    int pos);
char *get_last_word(const char *buffer);
char *get_suggestion(const char *buffer, global_t *global);

///////////////////////////////////////////////////////////////////////////////
/// utils
///////////////////////////////////////////////////////////////////////////////

int is_all_spaces(const char *str);
char *my_strstr_quote(const char *str, const char *to_find);
int cd_path(char **args, global_t *global, char *cwd, char *new_path);
int print_file(char const *file); // For marin and 42 built-ins
char *where_am_i(char *last_word, char **where);
global_t init_global(char **envp);
void free_global(global_t *global);
void manage_rc_file(global_t *global);
int print_array(char **array);

///////////////////////////////////////////////////////////////////////////////
/// jobs
///////////////////////////////////////////////////////////////////////////////

int display_jobs(void *data);
int jobs_buildin(global_t *global);
void add_jobs(global_t *global, pid_t pid, char **command,
    enum JOBS_STATE state);
void check_finished_jobs(global_t *global);
int builtin_fg(global_t *global, char *input);
void remove_job_by_pid(linked_list_t *list, pid_t pid);
int builtin_bg(global_t *global, char *input);
int get_job_id_by_pid(linked_list_t *list, pid_t pid);
jobs_t *get_job_by_id(linked_list_t *list, int id);
void free_jobs(linked_list_t **list);

#endif /* !HEADER */
