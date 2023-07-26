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
	_printf("Exiting the shell status: %d\n", status);
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

