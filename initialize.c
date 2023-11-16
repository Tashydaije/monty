#include "monty.h"

/**
 * init_args - initializes the global variable
 *             and allocate its memory
 * @_args: global variable
 *
 * Return: void
 */

void init_args(void)
{
	_args = malloc(sizeof(argMonty));
	if (!_args)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_args();
		exit(EXIT_FAILURE);
	}
	_args->stream = NULL;
	_args->line = NULL;
}
