#include "shell.h"

/**
 * _EOF - A function that checks if buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
