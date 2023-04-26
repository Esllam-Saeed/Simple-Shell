#include "shell.h"

/**
 * trimLeadingWhiteSpace - A function to remove leading white space
 * @str: The pointer to buffer.
 * Return nothing.
 */
void trimLeadingWhiteSpace(char *str)
{
	int i, j = 0;
	int len = _strlen(str);

	for (i = 0; i < len && str[i] == ' '; i++)
	;

	if (i > 0)
	{
		while (i < len)
		{
			str[j] = str[i];
			j++;
			i++;
		}
		str[j] = '\0';
	}
}
