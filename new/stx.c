#include "main.h"

/**
 * _strlen - counts the length of a string
 * @str: the string
 * Return: 1
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcat - adds a string to the destination
 * @dest: the rceiver
 * @src: the source
 * Return: the destination
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + strlen(dest);

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}


/**
 * _strtok - romove tokens
 * @delim: the delimiter
 * @str: the string
 * Return: token
 */
char *_strtok(char *str, const char *delim)
{
	static char *p;
	int len;
	char *ptr;

	if (str != NULL)
	{
		p = str;
	}
	if (p == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (p[len] != '\0' && strchr(delim, p[len]) == NULL)
	{
		len++;
	}
	if (p[len] == '\0')
	{
		ptr = p;
		p = NULL;
		return (ptr);
	}
	p[len] = '\0';
	ptr = p;
	p = p + len + 1;
	return (ptr);
}

/**
 * _printf - prints to screen
 * @format: the specifer
 * Return: 1
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = vfprintf(stdout, format, args);
	va_end(args);
	return (count);
}

/**
 * _strchr - searches for a string
 * @str: the string to be searched
 * @c: the counter
 * Return: 1
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
