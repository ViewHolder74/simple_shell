#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <errno.h>
#define MAX_COMMAND_LENGTH 1024

/**
 * lineptr_exec - function that executes cmd
 * @lineptr: command to execute
 * @args: argument vector
 * @envp: environment variable
 * Return: 0 if successful, -1 if error
 */
int lineptr_exec(char *lineptr, char **args, char **envp)
{
	char *path = getenv("PATH");
	char *pathCpy = strdup(path);
	char *token, **dir, *delim = ":";
	char full_path[MAX_COMMAND_LENGTH];

	if (strcmp(lineptr, "exit") == 0)
		exit(0);
	else if (strcmp(lineptr, "env") == 0)
	{
		dir = envp;
		while (*dir != NULL)
		{
			printf("%s\n", *dir);
			dir++;
		}
		return (0);
	}
	if (pathCpy == NULL)
		return (-1);
	if (strchr(lineptr, '/') != NULL)
		execve(lineptr, args, envp);
	else
	{
		token = strtok(pathCpy, delim);
		while (token != NULL)
		{
			_strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, lineptr);
			execve(full_path, args, envp);
			if (errno != ENOENT)
			{
				free(pathCpy);
				return (-1);
			}
			token = strtok(NULL, delim);
		}
	free(pathCpy);
	}
	return (-1);
}

/**
 * main - defines a unix interprater
 * @argc: argment count
 * @argv: argument vector
 * @envp: environment variable
 * Return: 0
 */

int main(int argc, char **argv, char **envp)
{
	char *buffer = "$ ", *token;
	char *lineptr = NULL, *delim = " ";
	char *args[MAX_COMMAND_LENGTH];
	size_t n = 0;
	ssize_t num_char;
	int result, count;
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", buffer);
		fflush(stdout);
		num_char = getline(&lineptr, &n, stdin);
		if (num_char == -1)
		{
			printf("\n");
			break;
		}
		if (num_char > 0 && lineptr[num_char - 1] == '\n')
			lineptr[num_char - 1] = '\0';
		token = strtok(lineptr, delim);
		for (count = 0; token != NULL; count++)
		{
			args[count] = token;
			token = strtok(NULL, delim);
		}
		args[count] = NULL;
		result = lineptr_exec(args[0], args, envp);
		if (result == -1)
			perror("Error");
	}
	free(lineptr);
	return (0);
}
