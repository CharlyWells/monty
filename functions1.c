#include "monty.h"

/**
 * stack_pall - Function to handle the pall opcode
 * @stack: Double pointer to the top of the stack
 * @line_num: Line number where the opcode appears in the file
 *
 * Return: void
 */
void stack_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current_node = *stack;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}

	(void)line_num;
}

/**
 * stack_pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 *
 * Return: void
 */
void stack_pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		free_global();
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * stack_pop - removes the top element from the stack
 * @stack

