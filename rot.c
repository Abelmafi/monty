#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @head: linked list head pointer.
 * @l_count: line count:
 *
 * Return: always nothing.
 */
void rotl(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	stack_t *current = *head, *tmp = *head;

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = current;
	if ((*head)->next)
		*head = (*head)->next;
	current->prev = current->next;
	current->next = NULL;
}
