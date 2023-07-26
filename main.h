#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>


void execmd(char **argv);
char *get_path(char *cmd);
void parse(char *cmd, char **argv);
void _exit(int status);
void _error(const char *msg);

int built_cd(char **argv);
int built_pwd();
int built_setenv(char *var, char *value);
void built_env();
void alias(char **argv);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

int _strlen(const char *str);
char* _strcat(char *dest, const char *src);
int _printf(const char *format, ...);
char* _strtok(char *str, const char *delim);
char* _strchr(const char *str, int c);

size_t _strcspn(const char* str, const char* reject);
char *_strdup(const char* str);
char *_strstr(const char *haystack, const char *needle);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
int check(char **argv);


#endif
