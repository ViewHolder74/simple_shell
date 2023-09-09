#include <stdio.h>
#include <stdlib.h>
#include "main.h"

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
	int status;

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
		if (num_char > 0 && lineptr[num_char -1] == '\n')
			lineptr[num_char - 1] = '\0';
		pid = fork();
		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			char *arg_passed[] = {lineptr, NULL};
			execve(lineptr, arg_passed, NULL);
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
