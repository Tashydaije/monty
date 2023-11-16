#include "monty.h"

/**
 * init_args - initializes the global variable
 *             and allocate its memory
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
	_args->opcode = malloc(sizeof(instruction_t));
	if (!_args->opcode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_args();
		exit(EXIT_FAILURE);
	}
	_args->stream = NULL;
	_args->line = NULL;
	_args->tokens = NULL;
	_args->head = NULL;
	_args->line_num = 0;
	_args->num_tokens = 0;
	_args->stack_len = 0;
}
