#include "shell.h"

/**
 * _strlen - counts the length of the variables
 *
 * @str: the strings
 *
 * Return: number of strings count
 */

size_t _strlen(const char *str)
{
	size_t len = 0;
	
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcat - adds the src and destinatin together
 *
 * @src: the source of the strings
 *
 * @dest: the destination where the strings are going.
 *
 * Return: destinatin
 */
char *_strcat(char *dest, const char *src)
{
       	char *ptr = dest;
	
	while (*ptr != '\0')
        {
		ptr++;
	}
        while (*src != '\0')
        
	{
		*ptr = *src;
                ptr++;
                src++;
        }

        *ptr = '\0';

        return (dest);
}

/**
 * _strcpy - copies from one source into aother
 *
 * @src: the source of the strings to be copied rom
 *
 * @dest: the destination to received the strings
 *
 * Return: dest*/
char *_strcpy(char *dest, const char *src)
{
        char *ptr = dest;

        while (*src != '\0')
        {
                *ptr = *src;
                ptr++;
                src++;
        }
        dest = '\0';
        return (dest);
}

