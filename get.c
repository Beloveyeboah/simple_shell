#include "shell.h"

/**
 * _getline - gets command from the user
 *
 * Return: void
 **/

char *_getline()
{
	char *ptr;
	size_t buf;

	ptr = NULL;
	buf = 0;
	getline(&ptr, &buf, stdin);
	return (ptr);
}
