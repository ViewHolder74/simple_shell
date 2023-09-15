#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#define MAX_COMMAND_LENGTH 1024

/* utility.c */
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *full_path, char *token);
char *_strchr(char *s, char c);
/* utility.c */

int _putchar(char c);

/* utility2.c */
int _strlen(char *s);
/* utility2.c */

#endif
