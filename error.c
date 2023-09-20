#include "shell.h"

/**
 * _puterror - Prints an error message to the standard error stream
 * @err: The error message to print
 *
 * Return: Void
 */
void _puterror(char *err)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(err);
	num_written = write(STDERR_FILENO, err, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
