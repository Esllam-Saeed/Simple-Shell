#include "shell.h"

/**
 * print_env - A function that prints all enviromental variables.
 * @envp: A pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		write(1, envp[i], _strlen(envp[i]));
		write(1, "\n", 1);
		i++;
	}
}
