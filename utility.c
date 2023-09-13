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
char *strcpy(char *dest, char *src)
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
 * strdup - a function that duplicates string
 * *mainstring - main string to be inputed
 * @noftimes - number of times to duplicate string
 *
 * Return: 0 on success else -1 on failure
 */
void strdup(const char *mainstring, int noftimes)
{
	int i, noftimes;
	char *mainstring;

	if (mainstring == NULL)
	{
		return (NULL);
	}

	for (int i = 0; i < noftimes; i++)
	{
		printf("%s\n", mainstring);
	}

}
