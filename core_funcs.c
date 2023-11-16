#include "monty.h"

/**
 * tokenizer - Tokenize the line read from the stream.
 *
 * Return: void
 */

void tokenizer(void)
{
	int i;
	char *token = NULL, *line_copy = NULL;

	line_copy = malloc(strlen(_args->line) + 1);
	if (!line_copy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_args();
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, _args->line);
	_args->num_tokens = 0;
	token = strtok(line_copy, DELIMS);
	while (token)
	{
		_args->num_tokens += 1;
		token = strtok(NULL, DELIMS);
	}
	_args->tokens = malloc(sizeof(char *) * (_args->num_tokens + 1));
	if (!_args->tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_args();
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, _args->line);
	token = strtok(line_copy, DELIMS);
	for (i = 0; token; i++)
	{
		_args->tokens[i] = malloc(strlen(token) + 1);
		if (!_args->tokens[i])
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_args();
			exit(EXIT_FAILURE);
		}
		strcpy(_args->tokens[i], token);
		token = strtok(NULL, DELIMS);
	}
	_args->tokens[i] = NULL;
	free(line_copy);
}

/**
 * get_op_func - gets the opcode and func it points to
 *
 * Return: void
 */

void get_op_func(void)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (_args->num_tokens == 0)
		return;

	for (; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, _args->tokens[0]) == 0)
		{
			_args->opcode->opcode = opcodes[i].opcode;
			_args->opcode->f = opcodes[i].f;
			return;
		}
	}
	opcode_err(_args->tokens[0]);
}

/**
 * run_op_func- Runs the opcode
 *
 * Return: void
 */

void run_op_func(void)
{
	stack_t *stack = NULL;

	if (!_args->opcode->f)
		return;

	_args->opcode->f(&stack, _args->line_num);
}
