#include "main.h"

/**
 * main - starting point of the progarmme
 *
 * @argv: the array use to execute the point
 *
 * @ac: the counter of the line
 *
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *prompt = "$ ", *comment, *d, *tok;
	char *read = NULL, *readx = NULL;
	size_t n = 0;
	ssize_t gline;
	const char *delim = " \n";
	int i, k = 0, status = system(readx), ext;
	pid_t my_pid;

	(void) ac;

	while (1)
	{
	       	write(STDOUT_FILENO, prompt, 2);
		 gline = _getline(&read, &n, stdin);
		 if (gline == -1)
		 {
			 perror("Error: Failed:\n");
			 return (-1);
		 }
		readx = malloc(sizeof(char) * gline);
		 if (read == NULL)
		 {
			 perror("Error: no inputs");
			 return (-1);
		 }
		 readx = _strdup(read);
		 tok = _strtok(read, delim);
		 while (tok)
		 {
			 k++;
			 tok = _strtok(NULL, delim);
		 }
		 argv = malloc(sizeof(char *) * k);
		 readx[_strcspn(readx, "\n")] = '\0';
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
		 if ((d = _strstr(readx, "$?")) != NULL)
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
		 if  (_strcmp(argv[0], "exit") == 0)
		 {
			 break;
		 }
		 else if (_strcmp(argv[0], "env") == 0)
		 {
			 built_env(argv);
			 continue;
		 }
		 else if (_strcmp(argv[0], "setenv") == 0)
		 {
			 built_setenv(argv);
			 continue;
		 }
		 else if (_strcmp(argv[0], "unsetenv") == 0)
		 {
			 built_unsetenv(argv);
			 continue;
		 }
		 else if (_strcmp(argv[0], "cd") == 0)
		 {
			 built_cd(argv);
			 continue;
		 }
		 else if (_strcmp(argv[0], "pwd") == 0)
		 {
			 built_pwd(argv);
			 continue;
		 }
		 argv[i] = NULL;
		 execmd(argv);
	}
	free(readx);
	free (read);
	return (0);
}
