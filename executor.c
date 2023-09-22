#include "shell.h"

/**
 * executor - starts executing everything
 * @current_command: try to check current token
 * @type_command: parse token
 *
 * Return: void function
 */

void executor(char **current_command, int type_command)
{
	pid_t PID;
	ShellData gb;

	initializeShellData(&gb);

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(current_command, type_command);
		else
		{
			waitpid(PID, &gb.status, 0);
			gb.status >>= 8;
		}
	}
	else
		execute_command(current_command, type_command);
}
