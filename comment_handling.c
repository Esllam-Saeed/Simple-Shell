#include "shell.h"

/**
 * comment_handling - A function that ignores a comment
 * @buffer: The pointer to input string.
 * Return: command with out comments.
 */
char *comment_handling(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '#')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
