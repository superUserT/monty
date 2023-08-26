#include "monty.h"

/**
 * f_swapitem - swaps the top two elements of the stack.
 * @stack: Stack
 * @line_number: Number of the line
 */

void f_swapitem(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		f_cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
/**
 * f_popitem - removes the top element of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */

void f_popitem(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		f_cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
/**
 * f_addint - function add two integer
 * @stack: Stack list
 * @line_number: Number of the line
 */


void f_addint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		f_cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	f_popitem(stack, line_number);
}


/**
 * f_nopvoid - function void
 * @stack: Stack list
 * @line_number: Number of the line
 */


void f_nopvoid(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * f_substack - subtracts the top element of the stack from the second.
 * @stack: Stack list
 * @line_number: Number of line
 */

void f_substack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int sub = 0;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		f_cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	sub = current->next->n - current->n;
	current->next->n = sub;
	f_popitem(stack, line_number);
}