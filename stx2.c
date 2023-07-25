#include "main.h"

/**
 * _getline - reads from  astream of inputs
 * @lineptr: the pointer to the strings
 * @n: the number of element in the lineptr
 * @stream: the strem of the inputs
 * Return: the pointer
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t gline;

	gline = getline(lineptr, n, stream);
	return (gline);
}

/**
 * _strcspn - remove a token from the string
 * @str: the string
 * @reject: the string not accepted
 * Return: 1
 */
size_t _strcspn(const char *str, const char *reject)
{
	size_t count = 0;

	while (*str)
	{
		if (strchr(reject, *str))
		{
			break;
		}
		count++;
		str++;
	}
	return (count);
}

/**
 * _strdup - copies from a source into a destination
 * @str: the string
 *
 * Return: str
 */
char *_strdup(const char *str)
{
	char *sun = malloc(strlen(str) + 1);

	if (sun != NULL)
	{
		strcpy(sun, str);
	}
	return (sun);
}

/**
 * _strstr - searches for a words in a string
 * @haystack: the words to be searched with in
 * @needle: the searced string
 * Return: the ned
 */
char *_strstr(const char *haystack, const char *needle)
{
	size_t needle_len = strlen(needle);

	while (*haystack)
	{
		if (strncmp(haystack, needle, needle_len) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
/**
 * _strcmp - compares among a string
 * @str1: the first
 * @str2: the second
 * Return: 1
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
