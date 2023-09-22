#include "shell.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 *@input_string: input to be parsed
 *@delim: delimiter to be used, needs to be one character string
 *
 *Return: array of tokens
 */
char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 * non_interactive - handles non_interactive mode
 *
 * Return: void
 */
void non_interactive(void)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;
	ShellData gb;

	initializeShellData(&gb);

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&gb.line, &n, stdin) != -1)
		{
			remove_newline(gb.line);
			remove_comment(gb.line);
			gb.commands = tokenizer(gb.line, ";");
			for (i = 0; gb.commands[i] != NULL; i++)
			{
				current_command = tokenizer(gb.commands[i], " ");
				if (current_command[0] == NULL)
				{
					free(current_command);
					break;
				}
				type_command = parse_command(current_command[0]);
				executor(current_command, type_command);
				free(current_command);
			}
			free(gb.commands);
		}
		free(gb.line);
		exit(gb.status);
	}
}
