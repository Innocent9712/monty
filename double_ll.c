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

	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
		return (NULL);
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;
	if (*head != NULL)
		(*head)->prev = temp;
	*head = temp;
	return (temp);
}

/**
 * print_dlistint - print every item in a linked list h
 * @h: head of linked list
 *
 * Return: number of nodes in linked list
 */

size_t print_dlistint(const stack_t *h)
{
	size_t num;
	stack_t *current;

	if (h == NULL)
		return (0);

	current = malloc(sizeof(stack_t));
	current->prev = h->prev;
	current->n = h->n;
	current->next = h->next;
	num = 0;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		num++;
		current = current->next;
	}

	free(current);
	return (num);
}
