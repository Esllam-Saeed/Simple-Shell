#include "shell.h"

#define MAX_COMMANDS 1024
#define MAX_COMMAND_LENGTH 1024

/**
 * semicolon_handle - A function that checks ; presence
 * @buffer: The pointer to input string.
 * @shell: The pointer to the name of shell.
 * @envp: The pointer to the enviromental variables.
 * @iterations: Number of executed cycles.
 * Return: nothing
 */
void semicolon_handle(char *buffer, char *shell, char **envp, int iterations)
{
	char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];
	int i = 0, j;
	char *token = strtok(buffer, ";");

	while (token != NULL && i < MAX_COMMANDS)
	{
		_strcpy(commands[i], token);
		token = strtok(NULL, ";");
		i++;
	}

	for (j = 0; j < i; j++)
	{
		run(commands[j], shell, envp, iterations);
		iterations++;
	}
}
