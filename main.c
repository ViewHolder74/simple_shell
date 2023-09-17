#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <errno.h>
#include <fcntl.h>
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
	char *path = getenv("PATH"), *pathCpy = _strdup(path);
	char *token, **dir, *delim = ":", full_path[MAX_COMMAND_LENGTH];

	if (_strcmp(lineptr, "exit") == 0)
		exit(0);
	else if (_strcmp(lineptr, "env") == 0)
	{
		dir = envp;
		while (*dir != NULL)
		{
			write(STDOUT_FILENO, *dir, _strlen(*dir));
			write(STDOUT_FILENO, "\n", 1);
			dir++;
		}
		return (0);
	}
	if (pathCpy == NULL)
		return (-1);
	if (_strchr(lineptr, '/') != NULL)
		execve(lineptr, args, envp);
	else
	{
		token = strtok(pathCpy, delim);
		while (token != NULL)
		{
			_strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, lineptr);
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
 * handle_cmd - function that execute a single command
 * @lineptr: command string
 * @argv: argument vector
 * @envp: environment variable
 * Return: void
 */
void handle_cmd(char *lineptr, char **argv, char **envp)
{
	char *token, *delim = " ";
	char *args[MAX_COMMAND_LENGTH];
	int count = 0, nstr;

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		args[count++] = token;
		token = strtok(NULL, delim);
	}
	args[count] = NULL;
	nstr = lineptr_exec(args[0], args, envp);
	if (nstr == -1)
		perror(argv[0]);
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
	char *buffer = ":) ", *lineptr = NULL;
	size_t n = 0;
	ssize_t num_char;
	int fd = STDIN_FILENO;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("File can't be openned");
			return (1);
		}
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, buffer, _strlen(buffer));
		fflush(stdout);
		num_char = getline(&lineptr, &n, stdin);
		if (num_char == -1)
		{
			_putchar('\n');
			break;
		}
		if (num_char > 0 && lineptr[num_char - 1] == '\n')
			lineptr[num_char - 1] = '\0';
		handle_cmd(lineptr, argv, envp);
	}
	free(lineptr);
	if (argc > 1)
		close(fd);
	return (0);
}
