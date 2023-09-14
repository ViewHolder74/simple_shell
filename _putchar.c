#include <unistd.h>

/**
 * _putchar - a function that writes character c to standard output
 * @c: character c to be print
 *
 * Return: 1 0n success
 * else, return -1 On error, and errno is set accordingly
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
