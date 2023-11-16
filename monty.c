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
		/** tokenize cmd, get opcode **/
	}
	close_stream();
	free_args();

	return (EXIT_SUCCESS);
}
