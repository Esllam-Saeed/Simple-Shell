#include "shell.h"

/**
 * main - A function that runs our shell.
 * @argc: The number of inputed arguments.
 * @argv: The pointer to array of inputed arguments.
 * @envp: The pointer to array of enviromental variables.
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char **argv, char **envp)
{
	char *buffer = NULL;
	size_t buf_size = 0;
	ssize_t chars = 0;
	int iterations = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv, envp);
	while (1)
	{
		iterations++;
		prompt();
		signal(SIGINT, handle_signal);
		chars = _getline(&buffer, &buf_size, stdin);
		trimLeadingWhiteSpace(buffer);
		if (chars == EOF)
			_EOF(buffer);
		else if (*buffer == '\n' || *buffer == '#')
			free(buffer);
		else
		{
			buffer = comment_handling(buffer);
			semicolon_handle(buffer, argv[0], envp, iterations);
			free(buffer);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * prompt - A function that prints the prompt
 * Return: Nothing.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "simple_Shell>> ", 16);
}


/**
 * handle_signal - A function to handle Ctrl + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void handle_signal(__attribute__((unused)) int signals)
{
	write(STDOUT_FILENO, "\nsimple_Shell>> ", 16);
}
