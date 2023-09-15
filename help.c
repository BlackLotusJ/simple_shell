#include <stdio.h>
#include <unistd.h>
#include "shell.h"


/**
 * _puts - prints a string followed by a new line
 * @str: string to be output
 */
void _puts(char *str)
{
	while (*str != "\0")
		_putchar(str++);
	_putchar('\n');
}

/**
 * _strncmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the max number of bytes to compare
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}
