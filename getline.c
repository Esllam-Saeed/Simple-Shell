#include "shell.h"

/**
 * _getline - getline function.
 * @buffer: input in shell.
 * @size: size input.
 * @fp: file pointer.
 * Return: Always 0.
 */
int64_t _getline(char **buffer, size_t *size, FILE *fp)
{
	char chars[1024];

	if (buffer == NULL || size == NULL || fp == NULL)
	{
		fputs("WRONG ARGUMENTS.\n", stderr);
		return (-1);
	}
	if (*buffer == NULL)
	{
		*size = sizeof(chars);
		*buffer = malloc(*size);
		if (*buffer == NULL)
		{
			perror("Unable to allocate memory for buffer");
			return (-1);
		}
	}
	(*buffer)[0] = '\0';
	while (fgets(chars, sizeof(chars), fp) != NULL)
	{
		if (*size - strlen(*buffer) < sizeof(chars))
		{
			*size *= 2;
			*buffer = realloc(*buffer, *size);
			if (*buffer == NULL)
			{
				perror("Unable to re-allocate memory for buffer");
				free(buffer);
				return (-1);
			}
		}
		strcat(*buffer, chars);
		if ((*buffer)[strlen(*buffer) - 1] == '\n')
			return (strlen(*buffer));
	}
	return (-1);
}
