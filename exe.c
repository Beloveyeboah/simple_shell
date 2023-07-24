#include "main.h"

/**
 * execmd - executes the shell programm
 *
 * @argv: the commands to be executed
 *
 * Return: nothing
 */
void execmd(char **argv)
{
	char *cmd = NULL, *cmdx = NULL;
	pid_t pid = fork();
	int status;

	if (argv)
	{
		cmd = argv[0];
		cmdx = get_path(cmd);
		if (pid == -1)
		{
			_error("Fail: to fork process");
		}
		if (pid == 0)
		{
			if (execve(cmdx, argv, NULL) == -1)
			{
				_error("Error: not a command");
			}
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}

