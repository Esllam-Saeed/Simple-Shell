#include "shell.h"

/**
 * read_file - Read Commands From File
 * @filename: Filename
 * @argv: The pointer to array of inputed arguments.
 * @envp: The pointer to array of enviromental variables.
 * Return: nothing
 */

void read_file(char *filename, char **argv, char **envp)
{
	FILE *fp;
	char *cmd = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((_getline(&cmd, &len, fp)) != -1)
	{
		counter++;
		cmd = comment_handling(cmd);
		semicolon_handle(cmd, argv[0], envp, counter);
	}
	if (cmd)
		free(cmd);
	fclose(fp);
	exit(0);
}
