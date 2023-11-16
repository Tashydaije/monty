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
