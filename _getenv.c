#include "shell.h"

/**
  * _getenv - gets the environment value from a key
  * @name: string to search through environments
  * Return: value of the key as a string
  */
char *_getenv(char *name)
{
	size_t len;
	char *var;
	char *value;
	char **env;

	len = _strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		var = *env;
		if (!_strncmp(var, name, len) && var[len] == '=')
		{
			value = _strdup(var + len + 1);
			return (value);
		}
	}
	return (NULL);
}
