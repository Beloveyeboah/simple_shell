#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* STRINGS USED */
char* _strtok(char* str, const char* delim);
size_t _strlen(const char *str);
char * _strcat(char *dest, const char *src);
char * _strcpy(char *dest, const char *src);char * _strcpy(char *dest, const char *src);

/* get stings on the command lines*/
char *_getline();


#endif
