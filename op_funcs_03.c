#include "monty.h"

/**
 * _mod - find the modulus of the second value in a stack with the top value
 * @stack: stack to print
 * @line_number: current line of file
 * Description: Store the result in the second value and discard
 * the top value
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}
