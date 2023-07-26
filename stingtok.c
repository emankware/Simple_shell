#include <stdlib.h>
#include "shell.h"
#include "main.h"
/**
 * isDelim - function that checks if a character is one of the delimiters
 * @c: character
 * @delim: delimeters
 *
 * Return: 1 if it is a delimiter, 0 otherwise
 */
int isDelim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
/**
 * _strtok -this function finds token in a string
 * @str: string 
 * @delim: delimiters
 * @savePtr: state
 *
 * Return: the next token found in string,else NULL
 */
char *_strtok(char *str, char *delim, char **savePtr)
{
	char *ptr, *modifier, *end;
	int quoteFound = 0;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && isDelim(*ptr, delim))
		ptr++;
	modifier = ptr;
	if (*ptr == '\0')
	{
		return (NULL);
	}
	if (*ptr == '\'')
	{
		ptr++;
		modifier = _strchr(ptr, '\'');
		if (!modifier)
		{
			_printf("no matching quote found!\n");
			exit(-1);
		}
		*modifier = '\0';
		*savePtr = modifier + 1;
		return (_strdup(ptr));
	}
	while (*modifier)
	{
		if (*modifier == '\'')
			quoteFound = 1;
		if (isDelim(*modifier, delim) && quoteFound == 0)
			break;
		modifier++;
	}
	if (*modifier == '\0')
		*savePtr = modifier;
	else
		*savePtr = modifier + 1;
	*modifier = '\0';

	return (_strdup(ptr));

}
