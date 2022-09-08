#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always nothng.
 */
void rotr(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	stack_t *last, *bottom;

	if (!head || !*head || (*head)->next)
		return;
	bottom = *head;
	while (bottom->next)
		bottom = bottom->next;
	last = bottom->prev;
	last->next = NULL;
	bottom->prev = NULL;
	bottom->next = *head;
	(*head)->prev = bottom;
	*head = bottom;
}
