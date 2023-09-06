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
	char *buffer, *lineptr;
	size_t n = 0;
	ssize_t num_char;

	buffer = "<shell> $ ";

	while (1)
	{
		printf("%s", buffer);
		num_char = getline(&lineptr, &n, stdin);
		if (num_char == -1)
		{
			return (-1);
		}

		printf("%s\n", lineptr);
	}
	free(lineptr);

	return (0);
}
