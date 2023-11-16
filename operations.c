#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 */


void push(stack_t **stack, unsigned int line_number)
{
	if (_args->num_tokens <= 1 || !is_num(_args->tokens[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_args();
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (!(*stack))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_args();
		exit(EXIT_FAILURE);
	}
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	(*stack)->n = (int) atoi(_args->tokens[1]);
	if (_args->head)
	{
		 (*stack)->next = _args->head;
		 _args->head->prev = *stack;
	}
	_args->head = *stack;
	_args->stack_len += 1;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!_args->head)
		return;

	(void)stack;
	(void)line_number;
	temp = _args->head;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
