#include "monty.h"
/**
 * push - push int of data into the stack
 * @head: linked list head pointer.
 * @l_count: line count.
 *
 * Return: alwaya none.
 */
void push(stack_t **head, unsigned int l_count __attribute__((unused)))
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
