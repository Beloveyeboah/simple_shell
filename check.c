#include "main.h"

/**
 * check - checks the command
 * @argv: the array
 * Retrn: 1
 */
int check(char **argv)
{
	while (argv != 	NULL)
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			break;
		}
		else if (strcmp(argv[0], "env") == 0)
		{
			built_env(argv);
			continue;
		}
		else if (strcmp(argv[0], "setenv") == 0)
		{
			built_env(argv);
			continue;
		}
		else if (strcmp(argv[0], "cd") == 0)
		{
			built_cd(argv);
			continue;
		}
		else if (strcmp(argv[0], "pwd") == 0)
		{
			built_pwd(argv);
			continue;
		}
	}
	return (0);
}
