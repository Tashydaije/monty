#include "monty.h"

/**
 * free_args - Deallocates memory of arguments
 *
 * Return: void
 */

void free_args(void)
{
	if (!_args)
		return;

	if (_args->opcode)
	{
		free(_args->opcode);
		_args->opcode = NULL;
	}
	free_head();
	if (_args->line)
	{
		free(_args->line);
		_args->line = NULL;
	}
	free(_args);
}

/**
 * free_tokens - Deallocates memory of tokens
 *
 * Return: void
 */

void free_tokens(void)
{
	int i;

	if (!_args->tokens)
		return;

	for (i = 0; i < _args->num_tokens; i++)
	{
		free(_args->tokens[i]);
	}
	free(_args->tokens);
	_args->tokens = NULL;
}

/**
 * free_head - Deallocates memory of head
 *
 * Return: void
 */

void free_head(void)
{
	if (_args->head)
	{
		free_stack(_args->head);
		_args->head = NULL;
	}
}

/**
 * free_stack - Deallocates memory of stack
 * @head: The head of the stack
 *
 * Return: void
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	if (!head)
		return;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
