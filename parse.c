#include "main.h"

/**
 * parse - romoves token
 * @cmd: the command
 * @argv: the array
 * Return: cmd
 */
void parse(char *cmd, char **argv)
{
	char *tok, *cmdx = NULL;
	const char *delim = " \n";
	int i = 0, k = 0;

	cmdx = strdup(cmd);
	tok = strtok(cmd, delim);

	while (tok)
	{
		k++;
		tok = strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) *k);
	tok = strtok(cmdx, delim);
	for (i = 0; tok != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(tok));
		strcpy(argv[i], tok);
		tok = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(cmdx);
	free(cmd);
}
