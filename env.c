#include "shell.h"

/**
 *env - prints the current_environnement
 *@tokenized_command: command entered
 *
 *Return: void
 */

void env(char **tokenized_command __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (pair_ptr = *my_environ, name_cpy = name;
		     *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}
