#include "main.h"

/**
 * _exit - exit the shell
 *
 * @status: the status of the exit
 *
 * Return: status
 */
void _exit(int status)
{
	char *msg = "Exiting the shell\n";

	write(STDERR_FILENO, msg, strlen(msg));
	exit(status);
}

/**
 * _error - prints an error message
 *
 * @msg: the message
 *
 * Return: nothing
 */

void _error(const char *msg)
{
	perror(msg);
	_exit(1);
}

