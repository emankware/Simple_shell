#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "lists.h"

/**
 * print_alias - prints the value of an alias, if it exists by searching the
 * alias list stored in parameter struct.
 * @name: the name of the alias to print
 * @params: the parameter struct containing the alias list
 *
 * If the alias is found,value printed is stdout, else an error(stderr)
*/
void print_alias(char *name, param_t *params)
{
	unsigned int len = 0;
	list_t *ptr = params->alias_head;

	len = _strlen(name);
	while (ptr)
	{
		if (_strcmp_n(name, ptr->str, len - 1) == 0)
			_printf("%s=\'%s\'\n", ptr->str, ptr->val);
		ptr = ptr->next;
	}
	params->status = 0;
}

/**
 * print_all_aliases - This function iterates through the alias list and
 * prints all aliases in the alias list
 * @params: the parameter struct containing the alias list
 *
*/
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}

/**
 * print_list_alias - This function iterates through the linked list of aliases
 * and prints the name and value of each alias in a linked list
 * @head: it is the pointer to the head of the linked list
 *
*/
void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
			_printf("%s=\'%s\'\n", head->str, head->val);
	}
}
