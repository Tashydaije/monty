#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * file_stream - reads a file stream from a file.
 * @fileName: Name of the file
 *
 * Return: void
 */

void file_stream(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		stream_err(fileName);

	_args->stream = fopen(fileName, "r");
	if (!(_args->stream))
	{
		close(fd);
		stream_err(fileName);
	}
}

/**
 * close_stream - Closes the stream
 *
 * Return: void
 */

void close_stream(void)
{
	if (!_args->stream)
		return;
	fclose(_args->stream);
	_args->stream = NULL;
}
