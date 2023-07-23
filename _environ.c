#include "main.h"
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - This function gets the value of an environment variable from
 * linked list in the parameter structure
 * @name: the name of the environment variable.
 * @params: a pointer to the parameter structure
 *
 * Return: A pointer to the value of the environment variable, or NULL if not.
 */

char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
	{
		if (!_strcmp(name, ptr->str))
			return (_strdup(ptr->val));
		ptr = ptr->next;
	}
	return (NULL);
}
