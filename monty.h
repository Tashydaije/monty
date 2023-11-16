#ifndef __MONTY_H__
#define __MONTY_H__

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DELIMS " \n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arguments - store op codes
 * @stream: File stream
 * @line: a line of text input
 * @line_num: line number
 * @tokens: array of tokens
 * @num_tokens: number of tokens
 * @stack_len: length of stack
 * @head: head of stack
 * @opcode: opcode
 */

typedef struct arguments
{
	FILE *stream;
	char *line;
	unsigned int line_num;
	char **tokens;
	int num_tokens;
	int stack_len;
	stack_t *head;
	instruction_t *opcode;
} argMonty;

void init_args(void);
void file_stream(char *fileName);
void stream_err(char *fileName);
void free_args(void);
void free_tokens(void);
void free_head(void);
void free_stack(stack_t *head);
void close_stream(void);
void tokenizer(void);
void get_op_func(void);
void run_op_func(void);
void opcode_err(char *opcode);
int is_num(char *str);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pop_stack(void);

extern argMonty *_args;

#endif /* __MONTY_H__ */
