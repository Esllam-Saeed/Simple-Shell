#include "shell.h"

/**
 * _getPATH - A function to gets the full value from.
 * enviromental variable PATH.
 * @envp: The pointer to enviromental variables.
 * Return: All paths for commands.
 */
char **_getPATH(char **envp)
{
	char **path = NULL, *pathvalue;
	int i = 0;

	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			pathvalue = envp[i] + 5;
			path = split_string(pathvalue, ":");
			break;
		}
		i++;
	}
	return (path);
}
