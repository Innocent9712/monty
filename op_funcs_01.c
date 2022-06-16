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
