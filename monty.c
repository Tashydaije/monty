#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>

void nothing(void);
argMonty *_args = NULL;

/**
 * nothing - Does nothing.
 *
 * Return: void
 */

void nothing(void){}

/**
 * main - Entry point of monty application
 * @argc: Number of command arguments.
 * @argv: Array of command arguments.
 *
 * Return: 0 success, 1 otherwise
 */

int main(int argc, char **argv)
{
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_args();
	file_stream(argv[1]);

	while (getline(&_args->line, &n, _args->stream) != -1)
	{
		_args->line_num += 1;
		tokenizer();
		get_op_func();
		run_op_func();
		free_tokens();
	}
	close_stream();
	free_args();

	return (EXIT_SUCCESS);
}
