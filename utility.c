#include "main.h"

/**
 * *_strcpy - copies a string pointed to by source -src
 * which includes the terminating null byte (\0)
 * to the buffer pointed to by destination -dest
 * @dest: pointer to the buffer or destination in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to destination -dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0, i;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
