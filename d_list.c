#include "monty.h"
/**
 * add_node - add node at the top of linked list.
 * @head: head pointer of linked list
 * @num: linked list data.
 *
 * Return: 0 on failure and 1 on success.
 */
int add_node(stack_t **head, int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (0);
	}
	new->n = num;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (1);
}
