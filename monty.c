#include "monty.h"
#include <stdio.h>

argMonty *_args = NULL;

/**
 * main - Entry point of monty application
 * @argc: Number of command arguments.
 * @argv: Array of command arguments.
 *
 * Return: 0 success, 1 otherwise
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_args();
	file_stream(argv[1]);

	while (fgets(_args->line, BUFSIZ, _args->stream) != NULL)
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
