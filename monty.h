#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * struct global_s - Structure for managing global variables
 * @number: A pointer to a string representing a number
 * @file: A pointer to a FILE structure for file operations
 * @buf: A  pointer to a buffer for data manipulation
 * @stack: A pointer to a stack structure for stack operations
 * @is_stack: An integer flag indicating if stack is enabled (1) or ont (0)
 */
typedef struct global_s
{
	char *number;
	FILE *file;
	char *buf;
	stack_t *stack;
	int is_stack;
} global_t;

extern global_t s;

void stack_push(stack_t **head, unsigned int line_num);
void stack_pall(stack_t **head, unsigned int line_num);
void stack_pint(stack_t **head, unsigned int line_num);
void stack_pop(stack_t **head, unsigned int line_num);

void stack_enqueue(stack_t **, int element);
#endif
