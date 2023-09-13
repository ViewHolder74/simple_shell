#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#define MAX_COMMAND_LENGTH 1024

/**
 * _strdup - a function that duplicates string
 * _strcmp - a function that compares two strings
 */
char *_strcpy(char *dest, char *src);
int lineptr_exec(char *lineptr, char **args, char **envp);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

#endif
