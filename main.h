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


void execmd(char **argv);
char *get_path(char *cmd);

void _exit(int status);
void _error(const char *msg);

int built_cd(char **argv);
int built_pwd();
int built_unsetenv(char **argv);
int built_setenv(char **argv);
void built_env();
void alias(char **argv);

int _strlen(const char *str);
char *_strcat(char *dest, const char *src);
int _printf(const char *format, ...);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *str, int c);

#endif
