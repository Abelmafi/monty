#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always none.
 */
void swap(stack_t **head, unsigned int l_count)
{
	stack_t *tmp = NULL, *current = *head;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_count);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	current->next = tmp->next;
	current->prev = tmp;
	tmp->next = current;
	tmp->prev = NULL;
	*head = tmp;
}
