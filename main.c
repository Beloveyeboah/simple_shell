#include "main.h"

/**
 * main - starting point of the progarmme
 *
 * @argv: the array use to execute the point
 *
 * @argc: the counter of the line
 *
 * Retun: 0
 */
int main(int ac, char **argv)
{
	char *prompt = "$ ", *comment, *d;
	char *read = NULL, *readx = NULL;
	size_t n = 0;
	ssize_t gline;
	const char *delim = " \n";
	char *tok;
	int i, k = 0, status = system(readx), ext;
	pid_t my_pid;
	FILE *ptr = NULL;

	if (ac > 1)
	{
		ptr = fopen("argv[1]", "r");
		if (ptr == NULL)
		{
			perror("Error: failed to open in file mode");
			exit(1);
		}
		while (!feof(ptr))
		{
			fgets(read, 200, ptr);
			read[strcspn(read, "\n")] = 0;
			readx = malloc(sizeof(char) * 200);
			readx = strdup(read);

			tok = _strtok(read, delim);
			while (tok)
			{
				k++;
				tok = _strtok(NULL, delim);
			}
			argv = malloc(sizeof(char *) * k);
			tok = _strtok(readx, delim);
			for (i = 0; tok != NULL; i++)
			{
				argv[i] = malloc(sizeof(char) * strlen(tok));
				strcpy(argv[i], tok);
				tok = _strtok(NULL, delim);
			}
			argv[i] = NULL;
			execmd(argv);
		}
		free(readx);
		free(read);
	}

	else
	{
		while (1)
		{
			 write(STDOUT_FILENO, prompt, 2);
			 gline = getline(&read, &n, stdin);
			 if (gline == -1)
			 {
				 perror("Error: Failed:\n");
				 return (-1);
			 }
			 readx = malloc(sizeof(char) * gline);
			 if (readx == NULL)
			 {
				 perror("Error: no inputs");
				 return (-1);
			 }
			 readx = strdup(read);
			 tok = _strtok(read, delim);
			 while (tok)
			 {
				 k++;
				 tok = _strtok(NULL, delim);
			 }
			 argv = malloc(sizeof(char *) * k);
			 readx[strcspn(readx, "\n")] = '\0';
			 if ((comment = strchr(readx, '#')) != NULL)
			 {
				 *comment = '\0';
			 }
			 if ((d = strstr(readx, "$$")) != NULL)
			 {
				 my_pid = getpid();
				 _printf("%u\n", my_pid);
				 continue;
			 }
			 if ((d = strstr(readx, "$?")) != NULL)
			 {
				 ext = WEXITSTATUS(status);
				 _printf("%d\n", ext);
				 continue;
			 }
			 tok = _strtok(readx, delim);
			 for (i = 0; tok != NULL; i++)
			 {
				 argv[i] = malloc(sizeof(char) * _strlen(tok));
				 strcpy(argv[i], tok);
				 tok = _strtok(NULL, delim);
			 }
			 if  (strcmp(argv[0], "exit") == 0)
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
				 built_setenv(argv);
				 continue;
			 }
			 else if (strcmp(argv[0], "unsetenv") == 0)
			 {
				 built_unsetenv(argv);
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
			 execmd(argv);
		}
		free(readx);
		free(read);
	}
	return (0);
}

