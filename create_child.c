#include "shell.h"

/**
 * create_child - A function that creates a cild-process.
 * @cmd: The pointer to command
 * @shell: The pointer to the name of shell.
 * @envp: The pointer to the enviromental variables.
 * @iterations: Number of executed cycles.
 * Return: Nothing.
 */
void create_child(char **cmd, char *shell, char **envp, int iterations)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_cmd(cmd, 1);
	}
	else if (pid == 0)
	{
		execute(cmd, shell, envp, iterations);
		free_cmd(cmd, 0);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_cmd(cmd, 1);
		}
		free_cmd(cmd, 0);
	}
}
