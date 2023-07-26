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
 * Return: void
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
 * @var: the valuable
 *
 * @value: the value
 *
 * Return: 1
 */
int built_setenv(char *var, char *value)
{
	int ow = 1;
	char res;

	if (var == NULL || value == NULL)
	{
		printf("Usage: setenv VAR VALUE\n");
		return (0);
	}
	if (getenv(var) != NULL)
	{
		printf("Variable %s already exists. Overwrite? (y/n): ", var);
		scanf("%c", &res);
		if (res == 'n' || res == 'N')
		{
			return (0);
		}
		else
		{
			ow = 0;
		}
		if (setenv(var, value, ow) == 0)
		{
			printf("Variable %s has been set to %s\n", var, value);
			return (1);
		}
		else
		{
			perror("setenv");
		}
	}
	return (0);
}


/**
 * built_env - prints the env
 *
 * Return: nothing
 */
void built_env(void)
{
	extern char **environ;
	char **env;
	int i = 0;

	env = environ;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
