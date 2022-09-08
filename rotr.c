#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always nothng.
 */
void rotr(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	stack_t *temp = NULL, *swap = *head;

	if (!head || !*head || (*head)->next)
		return;
	while (swap)
	{
		temp = swap->prev;
		swap->prev = swap->next;
		swap->next = temp;
		swap = swap->prev;
	}
	if (temp)
		*head = temp->prev;
}
