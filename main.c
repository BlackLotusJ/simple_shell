#include "shell.h"

/**
 * initializeShellData - initialize shell data
 * Description: initaializes parameters to be used by reguired functions
 * @gb: global variable
 */
void initializeShellData(ShellData *gb)
{
	gb->commands = NULL;
	gb->line = NULL;
	gb->shell_name = NULL;
	gb->status = 0;
}
/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 *
 * applies the functions in utils and helpers
 * implements EOF
 * Prints error on Failure
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	ShellData gb;

	initializeShellData(&gb);

	signal(SIGINT, ctrl_c_handler);
	gb.shell_name = argv[0];
	while (1)
	{
		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&gb.line, &n, stdin) == -1)
		{
			free(gb.line);
			exit(gb.status);
		}
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

			/* initializer -   */
			executor(current_command, type_command);
			free(current_command);
		}
		free(gb.commands);
	}
	free(gb.line);
	return (gb.status);
}
