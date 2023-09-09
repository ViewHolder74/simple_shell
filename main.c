#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#define MAX_COMMAND_LENGTH 1024
/**
 * main - defines a unix interprater
 * @argc: argment count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *buffer = "$ ", *lineptr = NULL;
	size_t n = 0;
	ssize_t num_char;
	pid_t pid;
	int status, count = 0;

	(void)argc; (void)argv;

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
		pid = fork();
		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			char *args[MAX_COMMAND_LENGTH];
			char *token = strtok(lineptr, " ");
			for (count = 0; token != NULL; count++)
			{
				args[count] = token;
				token = strtok(NULL, " ");
			}
			args[count] = NULL;
			execve(args[0], args, NULL);
			perror("Error:");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (status == 0)
			{
				continue;
			}
		}
	}
	free(lineptr);

	return (0);
}
