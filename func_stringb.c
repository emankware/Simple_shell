#include "shell.h"
#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _strcpy - This function copies a string to another memory address
 * @src: a pointer to the source string
 * @dest: a pointer to the dest address
 *
 * Return: a pointer  to the dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

/**
 * _strcmp - This function compares two strings
 * @s1: str 1
 * @s2: str 2
 *
 * Return: int less than, equal to, or greater than 0 if s1 is, respectively
 * less than, equal to, or greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	int res = 0;

	do {
		res = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (res == 0);

	return (res);
}

/**
 * _strcmp_n - This function compares the bytes of two strings
 * @s1: str 1
 * @s2: str 2
 * @n: the number of bytes to compare
 *
 * Return: integer less than, equal to, or greater than 0 if s1 is,
 * less than, equal to, or greater than s2
 */

int _strcmp_n(char *s1, char *s2, int n)
{
	int i = 0, res = *s1 - *s2;

	while (i <= n)
	{
		res = *(s1++) - *(s2++);
		if (res != 0)
			break;
		i++;
	}

	return (res);
}


/**
 * _atoi - This function turns a string into an int
 * @s: the string to evaluate
 * Return: value of first number
 */
int _atoi(char *s)
{
	int k, tmp, len, mul = 1;

	k = 0;
	tmp = 0;

	len = _strlen(s);
	len--;
	while (len >= 0)
	{
		tmp = k;
		k = k + (s[len] - '0') * mul;
		if (k < tmp || n > INT_MAX)
			return (-1);
		len--;
		mul *= 10;
	}
	return (k);
}
