#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always nothng.
 */
void rotr(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	stack_t *bottom, *last;

	if (!head || !*head || !(*head)->next)
		return;
	bottom = *head;
	while (bottom->next)
		bottom = bottom->next;

	last = bottom->prev;
	bottom->next = *head;
	bottom->prev = NULL;
	last->next = NULL;
	(*head)->prev = bottom;
	*head = bottom;
}
