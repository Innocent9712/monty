#include "monty.h"

/**
 * add_dnodeint - add a node to the beginning of dlist h
 * @head: address of head of list
 * @n: data for the node
 *
 * Return: address of new node or NULL
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *temp;

	if (!head)
		return (NULL);

	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;
	if (*head != NULL)
		(*head)->prev = temp;
	*head = temp;
	return (temp);
}
