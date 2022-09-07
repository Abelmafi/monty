#include "monty.h"
/**
 * add_node - add node at the top of linked list.
 * @head: head pointer of linked list
 * @num: linked list data.
 *
 * Return: 0 on failure and 1 on success.
 */
stack_t *add_node(stack_t **head, int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = num;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
/**
 * free_stack - frees a dlistint_t linked list
 * @head: list head
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	if (head)
	{
		next = head->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
