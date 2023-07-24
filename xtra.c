#include "main.h"

/**
 * built_cd - function for chaingin directory
 *
 * @argv: the command
 *
 * Return: 1
 */


int built_cd(char **argv)
{
	char *last = NULL;

	if (argv[1] == NULL)
	{
		chdir(getenv("HOME"));
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		last = getenv("OLDPWD");
		if (last != NULL)
		{
			chdir(last);
			write(STDOUT_FILENO, last, sizeof(last + '\n'));
		}
		else
		{
			perror("Last directory cannot be found");
		}

	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			perror("Error: cd");
			return (-1);
		}

	}
	return (0);
}

/**
 * built_pwd - prints the curret working directory of the shell
 * Retun - void
 */
int built_pwd(void)
{
	char cwd[200];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(STDOUT_FILENO, cwd, strlen(cwd));
		return (0);
	}
	else
	{
		perror("Error: pwd");
		return (-1);
	}
}

/**
 * built_setenv - set the env
 *
 * @argv: the command
 *
 * Return: 1
 */
int built_setenv(char **argv)
{
	extern char **environ;
	char **env;
	char *msg = "Too many arguments\n";

	if (argv[1] == NULL)
	{
		env = environ;
		while (*env != NULL)
		{
			_printf("%s", *env);
			env++;
		}
	}
	else if (argv[3] != NULL)
	{
		write(STDOUT_FILENO, msg, sizeof(msg));
	}
	else
	{
		if (setenv(argv[1], argv[2], 1) == -1)
		{
			perror("Error: setenv");
			return (-1);
		}

	}
	return (0);
}

/**
 * built_unsetenv - prints the unsetenv values
 *
 * @qrgv: the commands
 *
 * Return: 1
 */

int built_unsetenv(char **argv)
{
	char *msg = "Error: unsetenv\n";

	if (argv[1] == NULL)
	{
		write(STDOUT_FILENO, msg, sizeof(msg));
	}
	else
	{
		if (unsetenv(argv[1]) == -1)
		{
			perror("Error: unsetenv");
			return (-1);
		}

	}
	return (0);
}

/**
 * built_env - prints the env
 *
 * Return: o
 */
void built_env(void)
{
	extern char **environ;
	char **env;

	env = environ;
	while (env != NULL)
	{
		_printf("%s\n", *env++);
	}

}
