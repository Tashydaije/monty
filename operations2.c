#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (_args->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_args();
		exit(EXIT_FAILURE);
	}
	_args->head->next->n += _args->head->n;
	pop_stack();
	_args->stack_len -= 1;
}

/**
 * nop - Does nothing.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
