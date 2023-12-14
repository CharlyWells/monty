#include "monty.h"

/**
 * stack_push - Function to handle the push opcode
 * @stack: Double pointer to the top of the stack
 * @line_num: Line number where the opcode appears in the file
 *
 * Return: void
 */
void stack_push(stack_t **stack, unsigned int line_num)
{
    stack_t *new_node, *current_node = *stack;
    int num_to_push;

    if (!s.number)
    {
        free_global();
        fprintf(stderr, "L%d: usage: push integer\n", line_num);
        exit(EXIT_FAILURE);
    }
    num_checker(line_num);
    num_to_push = atoi(s.number);

    if (s.is_stack == 1)
    {
        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
            free_global();
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        new_node->n = num_to_push;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (!(*stack))
            *stack = new_node;
        else
        {
            while (current_node->next)
            {
                current_node = current_node->next;
            }
            new_node->prev = current_node;
            current_node->next = new_node;
        }
    }
    else
        stack_enqueue(stack, num_to_push);
}

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
    stack_t *current_node = *stack;

    if (!current_node)
    {
        free_global();
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", current_node->n);
}

/**
 * stack_pop - removes the top element from the stack
 * @stack: Pointer to the stack
 * @line_num: Line number
 *
 * Return: void
 */
void stack_pop(stack_t **stack, unsigned int line_num)
{
    stack_t *current_top = *stack;

    if (!current_top)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
        free_global();
        exit(EXIT_FAILURE);
    }

    if (!current_top->next)
    {
        *stack = NULL;
    }
    else
    {
        while (current_top->next->next)
        {
            current_top = current_top->next;
        }

        free(current_top->next);
        current_top->next = NULL;
    }
}

