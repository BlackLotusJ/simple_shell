#include <stdio.h>
#include <unistd.h>
#include "shell.h"


/**
 * _puts - prints a string followed by a new line
 * @str: string to be output
 */
void _puts(char *str)
{
	while (*str != '\0')
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

/**
 * _strcpy - copies the string pointed to by src
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';

	return (dest);
}

/**
 * _strncpy - copies a stirng
 * @dest: destination to copy
 * @src: source to copy
 * @n: amount of places to copy
 * Return: value of dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i =0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
	}
	return (dest);
}
