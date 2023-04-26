#include "shell.h"

/**
 * free_cmd - A function that frees all the memory allocated
 * for command and exit
 * the program if exit_flag is set.
 * @cmd: The pointer to allocated memory to free.
 * @exit_flag: A flag that indicates whether to exit the program or not.
 * Return: Nothing.
 */
void free_cmd(char **cmd, int exit_flag)
{
	char **p = cmd;

	if (!cmd)
	{
		if (exit_flag)
			exit(EXIT_FAILURE);
		return;
	}

	while (*p)
		free((void *) *p++);

	free((void *) cmd);
	if (exit_flag)
		exit(EXIT_FAILURE);
}
