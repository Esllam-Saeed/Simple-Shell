#include "shell.h"

/**
 * split_string - A function that split and create a full string command.
 * @s: The delimiter for strtok.
 * @buffer: The pointer to input string.
 * Return: A string with full command.
 */
char **split_string(char *buffer, const char *s)
{
	char *token = NULL, **cmd = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	cmd = malloc((bufsize + 1) * sizeof(char *));
	if (cmd == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_cmd(cmd, 0);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token != NULL)
	{
		cmd[i] = malloc(_strlen(token) + 1);
		if (cmd[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_cmd(cmd, 0);
			return (NULL);
		}
		_strcpy(cmd[i], token);
		token = strtok(NULL, s);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
