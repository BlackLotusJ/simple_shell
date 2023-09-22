#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct map - a struct that maps a command name to a function 
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */
typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

typedef struct
{
	char **commands;
	char *line;
	char *shell_name;
	int status;
}ShellData;

void initilaizeShellData(ShellData *gb);

/*HELPER FUNCTIONS*/
void print(char *string, int stream);
void _puts(char *str);
int _putchar(char c);
int _strlen(char *string);
void _strcpy(char *source, char *dest);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/*MAIN FUNCTIONS*/
char **tokenizer(char *, char *);
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);
void remove_newline(char *str);

/*Builtin Functions*/
void env(char **);
void quit(char **);

int check_for_builtin(char **args);
void shell_cd(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
void shell_help(void);
int shell_clear(char **args);

/*Utilities*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/*error*/
void _puterror(char *err);

extern void non_interactive(void);
extern void executor(char **current_command, int type_command);

#endif/*SHELL_H*/
