#include "shell.h"

/**
 * run- A function that run commands
 * @buffer: The pointer to input string.
 * @shell: The pointer to the name of shell.
 * @envp: The pointer to the enviromental variables.
 * @iterations: Number of executed cycles.
 * Return: nothing
 */
void run(char *buffer, char *shell, char **envp, int iterations)
{
	char **cmd = NULL;

	buffer[_strlen(buffer) - 1] = '\0';
	cmd = split_string(buffer, " \0");

	if (_strcmp(cmd[0], "exit") != 0)
		exit_shell(cmd);
	else if (_strcmp(cmd[0], "cd") != 0)
		change_directory(cmd[1]);
	else
		create_child(cmd, shell, envp, iterations);
}
