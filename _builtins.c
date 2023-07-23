#include "shell.h"
#include "lists.h"
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * get_builtin - This function searches for a builtin function
 * @params: Pointer to the param_t struct
 *
 * Return: Function pointer, NULL if not found.
 */

void (*get_builtin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", _clear},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
