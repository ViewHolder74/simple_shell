#include "main.h"

/**
 * *strcpy - copies a string pointed to by source -src
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


/**
 * _strdup - a function that duplicates string
 * @str: the string to be duplicated
 *
 * Return: a pointer to the string copied on success, else NULL for error
 */
char *_strdup(char *str)
{
	char *dupli;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dupli == NULL)
		return (NULL);

	while ((dupli[i] = str[i]) != '\0')
		i++;

	return (dupli);
}
