#include "monty.h"

/**
 * stream_err - Handles errors when reading a file
 * @fileName: The name of the file
 *
 * Return: void
 */

void stream_err(char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	exit(EXIT_FAILURE);
}

/**
 * opcode_err - Handles errors when reading an instruction
 * @opcode: The opcode
 *
 * Return: void
 */

void opcode_err(char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", _args->line_num, opcode);
	close_stream();
	free_tokens();
	free_args();
	exit(EXIT_FAILURE);
}
