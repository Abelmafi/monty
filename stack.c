#include "monty.h"
/**
 *
 *
 *
 *
 *
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));
	new->n = line_number;
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	*head = new;
}
