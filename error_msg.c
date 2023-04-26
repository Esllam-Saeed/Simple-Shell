#include "shell.h"

/**
 * error_msg - A function that prints message not found.
 * @shell: The shell name.
 * @iterations: Number of cycles.
 * @cmd: The pointer to the command.
 * Return: Nothing.
 */
void error_msg(char *shell, int iterations, char **cmd)
{
	char c;

	c = iterations + '0';
	write(STDOUT_FILENO, shell, _strlen(shell));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd[0], _strlen(cmd[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
