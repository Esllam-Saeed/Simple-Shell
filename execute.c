#include "shell.h"

/**
 * execute - A function that executes a command.
 * @cmd: The pointer to the command
 * @shell: The name of the shell.
 * @envp: The pointer to the enviromental variables.
 * @iterations: Number of executed cycles.
 * Return: Nothing.
 */
void execute(char **cmd, char *shell, char **envp, int iterations)
{
	char **path = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(cmd[0], "env") != 0)
		print_env(envp);
	if (stat(cmd[0], &st) == 0)
	{
		if (execve(cmd[0], cmd, envp) < 0)
		{
			perror(shell);
			free_cmd(cmd, 1);
		}
	}
	else
	{
		path = _getPATH(envp);
		while (path[i])
		{
			full_path = _strcat(path[i], cmd[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, cmd, envp) < 0)
				{
					perror(shell);
					free_cmd(path, 0);
					free_cmd(cmd, 1);
				}
				return;
			}
		}
		error_msg(shell, iterations, cmd);
		free_cmd(path, 0);
	}
}
