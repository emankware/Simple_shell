
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * free_params - This function frees the dynamically
 * allocated memory used by the param_t structure.
 * @params: a pointer to the param_t structure
 *
 */

void free_params(param_t *params)
{
	unsigned int k;

	if (params->buffer)
		free(params->buffer);
	if (params->nextCommand)
		free(params->nextCommand);
	free_list(params->env_head);
	free_list(params->alias_head);

	for (k = 0; params->args[k]; k++)
		free(params->args[k]);
	free(params->args);
	free(params);
}
