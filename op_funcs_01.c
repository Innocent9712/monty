#include "monty.h"

/**
 * _push - add onto a stack
 * @stack: stack to add onto
 * @line_number: current line of file
 */

void _push(stack_t **stack, unsigned int line_number)
{
	if (my_glob_vars.num && is_valid_num(my_glob_vars.num))
		add_dnodeint(stack, atoi(my_glob_vars.num));
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - print all values in a stack
 * @stack: stack to print
 * @line_number: current line of file
 */

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	while (stack && temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - print the top item on the stack
 * @stack: stack to print from
 * @line_number: current line of file
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * _pop - remove the top value in a stack
 * @stack: stack to print
 * @line_number: current line of file
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if ((*stack)->next)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(temp);
}
