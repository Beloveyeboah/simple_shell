#include "main.h"

/**
 * main - entry point of the shell
 * @argv: the vector of the arrays
 * @ac: the count of arguments on the command lines
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *prompt = "$ ", *cmd = NULL, *comment, *d;
	size_t n;
	ssize_t gline;
	int status = system(cmd), ext;
	char line[200];
	FILE *ptr = NULL;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		gline = getline(&cmd, &n, stdin);
		if (gline == -1)
		{
			perror("Error: end of commad\n");
			return (1);
		}

		if (cmd == NULL)
		{
			perror("Error: no command");
			continue;
		}
		cmd[strcspn(cmd, "\n")] = 0;
		comment = strchr(cmd, '#');
		if (comment != NULL)
		{
			*comment = '\0';
		}
		d = strstr(cmd, "$?");
		if (d != NULL)
		{
			ext = WEXITSTATUS(status);
			printf("%d\n", ext);
		}
		parse(cmd, argv);
		check(argv);
		execmd(argv);
	}
	free(cmd);

	if (ac > 1)
	{
		ptr = fopen(argv[1], "r");
		if (ptr == NULL)
		{
			perror("Eror");
			exit(EXIT_FAILURE);
		}
		while (!feof(ptr))
		{
			fgets(line, 20, ptr);
			line[strcspn(line, "\n")] = '\0';
			system(line);
		}
		fclose(ptr);
	}
	return (0);
}
