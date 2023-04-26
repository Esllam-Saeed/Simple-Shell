#include "shell.h"

/**
 * exit_shell - A function that exits the shell.
 * @cmd: The pointer to the command.
 * Return: Nothing.
 */
void exit_shell(char **cmd)
{
	int status = 0;

	if (cmd[1] == NULL)
	{
		free_cmd(cmd, 0);
		exit(EXIT_SUCCESS);
	}

	status = _atoi(cmd[1]);
	free_cmd(cmd, 0);
	exit(status);
}
