#include "shell.h"

int cause(char **argv, char **env)
{

	char *swahome = NULL;
	int z = 0;
	ssize_t char_nm;

	while (1)
	{
		printf("Simpleshell$ ");

		char_nm = getline(&swahome, &z stdin);
		if (char_nm == -1)
		{
			free(swahome);
			exit(EXIT_FAILURE);
		}
	}
}

