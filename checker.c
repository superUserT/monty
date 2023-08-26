#include "monty.h"


/**
 * _isdigit - Checks for a digit 0 through 9
 * Return: 0 or 1
 * @c: Variable
 **/

int _isdigit(char *c)
{
	char *inter = c;

	if (c == NULL)
		return (0);
	if (*inter == '-')
		inter++;

	for (; *inter != '\0'; inter++)
	{
		if ((*inter < '0' || *inter > '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * f_cleanStack - Frees mallocs and close de files
 * @stack: Stack
 */

void f_cleanStack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
	fclose(global.fd);
	free(global.line);
}
