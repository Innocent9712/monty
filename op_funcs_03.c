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

/**
 * _pchar - print top value in a stack as ASCII character
 * @stack: stack to print
 * @line_number: current line of file
 */


void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - print all values in a stack as ASCII character
 * @stack: stack to print
 * @line_number: current line of file
 */


void _pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp && stack)
	{
		if (temp->n < 1 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}


/**
 * _rotl - print top value in a stack as ASCII character
 * @stack: stack to print
 * @line_number: current line of file
 */


void _rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp, *current;

	if (!*stack || !(*stack)->next)
		return;
	temp = *stack;
	current = *stack;

	while (current->next != NULL)
		current = current->next;

	*stack = (*stack)->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;

}


/**
 * _rotr - print top value in a stack as ASCII character
 * @stack: stack to print
 * @line_number: current line of file
 */

void _rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp, *current;

	if (!*stack || !(*stack)->next)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	temp = current->prev;
	temp->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}
