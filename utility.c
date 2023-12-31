#include "main.h"

/**
 * _strcpy - copies a string pointed to by source -src
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

	dupli = malloc(sizeof(char) * (len + 1));

	if (dupli == NULL)
		return (NULL);

	while ((dupli[i] = str[i]) != '\0')
		i++;

	return (dupli);
}


/**
 * _strcmp - a function that compares two strings
 * @s1: the first string to compare
 * @s2: second string to compare
 *
 * Return: less(<) than 0 if s1 is less than s2, 0 if they're equal,
 *and greater than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * *_strcat - function commute srtings
 * @full_path: param pointer to a char
 * @token: param pointer to a char
 * Return: return value of dest
 */

char *_strcat(char *full_path, char *token)
{
	int i = 0, j = 0;

	while (full_path[i] != '\0')
	{
		i++;
	}

	while (token[j] != '\0')
	{
		full_path[i] = token[j];
		j++;
		i++;
	}

	full_path[i] = '\0';
	return (full_path);
}

/**
 * _strchr - finds a character in string
 * @s: string to perform character search
 * @c: characterto find
 * Return: pointer to the first occurence of
 * character in string or NULL if not found
 *
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		++s;
		++i;
	}
	return (s);
}
