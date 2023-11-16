#include "monty.h"

/**
 * is_num - Checks if a string is a number
 * @str: The string
 *
 * Return: 1 if true, 0 otherwise
 */

int is_num(char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * pop_stack - Pops the top element of the stack.
 *
 * Return: void
 */
void pop_stack(void)
{
	stack_t *temp;

	temp = _args->head;
	_args->head = _args->head->next;
	free(temp);
}
