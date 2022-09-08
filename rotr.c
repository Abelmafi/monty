#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always nothng.
 */
void rotr(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	stack_t *tmp = *head, *swap = *head;

	while (tmp)
	{
		tmp = tmp->next;
		swap->next = swap->prev;
		swap->prev = tmp;
		if (tmp)
			swap = tmp;
	}
	*head = swap;
}
