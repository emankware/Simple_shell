#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "lists.h"

/**
 * _alias - This function implements the alias shell command by
 * defining new aliases or printing existing aliase in the shell
 * @params: Pointer to a param_t struct.
 *
 */
void _alias(param_t *params)
{
	unsigned int a;

	if (params->tokCount == 1)
	{
		print_all_aliases(params);
		return;
	}
	for (a = 1; a < params->tokCount; a++)
	{
		if (_strchr(params->args[a], '='))
			set_alias(params->args[a], params);
		else
			print_alias(params->args[a], params);
	}
}

/**
 * set_alias - This function creates a new alias or updates an existing one
 * by setting a new alias or updates an existing one in the shell.
 * @name: it is the name of the alias to be set
 * @params: the state of shell
 *
 * Return: void
 */
void set_alias(char *name, param_t *params)
{
	char *val, *tmp = NULL;
	unsigned int a = 0, b = 1;

	while (name[a] && name[a] != '=')
		a++;
	if (name[a + 1] == '\'')
	{
		if (_strchr(&name[a + 2], '\''))
		{
			tmp = _strchr(&name[a + 2], '\'');
			*tmp = '\0';
			val = _strdup(&name[a + 2]);
			if (tmp[1] != '\0')
			{
				while (tmp[b] &&
					(tmp[b] == ' ' || tmp[b] == '\t' || tmp[b] == '\n'))
					b++;
				if (tmp[b] != '\0')
					set_alias(&tmp[b], params);
			}
		}
		else
		{
			_printf("Usage: alias name='value' [...]\n");
			return;
		}
	}
	else
		val = _strdup(&name[a + 1]);
	name[a] = '\0'; /* set = to terminater */
	make_alias(name, val, params);
}

/**
 * make_alias -This function creates a new alias and adds it to the alias list
 * using the given name and value
 * @name: alias name
 * @val: alias value
 * @params: the parameter struct containing the alias list
 */

void make_alias(char *name, char *val, param_t *params)
{
	list_t *h = params->alias_head;

	while (h)
	{
		if (!_strcmp(name, h->str))
		{
			free(h->val);
			h->val = val;
			h->valLen = _strlen(val);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	/* env var DNE */

	params->alias_head = add_node(&(params->alias_head), name, val);
	free(val);
	params->status = 0;
}
