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

/**
 * add_dnodeint_end - add new node to end of list h
 * @head: address to head of the list
 * @n: data of the node
 *
 * Return: address of the new element or NULL
 */

stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *temp, *current;

	if (!head)
		return (NULL);
	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
		return (temp);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = temp;
	temp->prev = current;
	return (temp);
}
