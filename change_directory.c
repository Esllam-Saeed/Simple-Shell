#include "shell.h"

/**
  * change_directory - A function that changes working directory.
  * @path: The new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int change_directory(const char *path)
{
	/*char *buffer = NULL;*/
	/*size_t size = 1024;*/

	if (path == NULL)
		/*path = getcwd(buffer, size);*/
		path = _getenv("HOME");
	else if (path[0] == '-')
		path = _getenv("OLDPWD");
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	setenv("OLDPWD", _getenv("PWD"), 1);
	return (1);
}
