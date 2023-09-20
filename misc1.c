#include "shell.h"

/**
 *remove_newline - removes new line from a string
 *@str: string to be used
 *
 *Return: void
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}
