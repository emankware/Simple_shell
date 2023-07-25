#include <stdlib.h>

/**
 * str_concat - This function concatenates two strings
 * @s1: the first string argument
 * @s2: the second string argument
 * Return: pointer to malloc,else NULL on failure
*/

char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int a = 0;
	int b = 0;
	int k = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[a] != '\0')
	{
		a++;
	}
	while (s2[b] != '\0')
	{
		b++;
	}
	ptr = malloc((a * sizeof(char)) + (b * sizeof(char)) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (a = 0; s1[a] != '\0'; a++)
	{
		ptr[a] = s1[a];
		k++;
	}
	for (b = 0; s2[b] != '\0'; b++)
	{
		ptr[k] = s2[b];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}
/**
 * string_nconcat - This function concatenates two strings
 * @s1: the first string argument
 * @s2: the second string argument
 * @n: the byte amount for s2
 * Return: Null on failure, else ptr to malloc
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int a = 0;
	unsigned int b = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[a] != '\0')
	{
		b++;
	}
	while (s2[b] != '\0')
	{
		b++;
	}
	if (n > b)
	{
		n = b;
	}
	ptr = malloc(sizeof(char) * (n + a) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (a = 0; s1[a] != '\0'; a++)
	{
		ptr[a] = s1[a];
	}
	for (b = 0; b < n; b++)
	{
		ptr[a + b] = s2[b];
	}
	ptr[a + b] = '\0';
	return (ptr);
}

/**
 *_strlen - This fuction returns the length of a string
 *@s: string
 *Return: 0 if null, else length without null byte
 */

int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
	{
		return (0);
	}

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strdup - This function copies a string to a new allocated block of memory
 * @str: string
 *
 * Return: pointer to duplicated string, else NULL
 */
char *_strdup(char *str)
{
	int length = 0; /* index of terminating null byte */
	char *ptr = NULL;

	if (!str)
		return (NULL);
	while (*str)
	{
		length++;
		str++;
	}
	ptr = (char *) malloc(sizeof(char) * (length + 1));
	if (ptr)
	{
		while (length >= 0)
			*(ptr + length--) = *(str--);
	}
	return (ptr);
}

/**
 * _strchr - This function locates a character in a string
 * @s: starting point
 * @c: the values to find
 *
 * Return: pointer to the beginning of the memory area
 */

char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}
