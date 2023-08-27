#include "monty.h"

extern int value;

/**
 * f_pint - prints the value at the top of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */

void f_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		f_cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
 * f_pushitem - pushs an item
 * @stack: is a parameter
 * @line_number: is value
 */

void f_pushitem(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = newNode(value);

	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * f_pall - prints all the values on the stack
 * @stack: is a parameter
 * @n: is value
 * Return: nothing
 */

void f_pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * newNode - creates a new node
 * @n: is a value
 * Return: new node
 */

stack_t *newNode(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * free_dlistint - Free a list.
 * @stack: Head node.
 * Return: Nothing.
 */

void free_dlistint(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_dlistint(current->next);
		free(current);
	}
}
