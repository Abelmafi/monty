#include "monty.h"
/**
 *
 *
 *
 *
 *
 */
void push(stack_t **head, unsigned int l_count)
{
	stack_t *new;
	int num;

	num = atoi(global.c);
	new = malloc(sizeof(stack_t));
	new->n = num;
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	*head = new;
}
