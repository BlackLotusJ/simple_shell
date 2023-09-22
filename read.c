#include "shell.h"

/**
 * read - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
