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

/**
 * pint - Prints the value at the top of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (!(_args->head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		close_stream();
		free_tokens();
		free_args();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", _args->head->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (!(_args->head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_stream();
		free_tokens();
		free_args();
		exit(EXIT_FAILURE);
	}
	pop_stack();
	_args->stack_len -= 1;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (_args->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_args();
		exit(EXIT_FAILURE);
	}
	temp1 = _args->head;
	temp2 = _args->head->next;
	temp1->next = temp2->next;
	if (temp1->next)
		temp1->next->prev = temp1;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp2->prev = NULL;
	_args->head = temp2;
}
