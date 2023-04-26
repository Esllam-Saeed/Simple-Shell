#include "shell.h"

/**
 * _strncmp - compares two strings and returns their difference
 * @s1: the first string
 * @s2: the second string
 * @bytes: number of bytes to compare
 * Return: number of bytes that differ
 */
int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}
