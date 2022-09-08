#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @head: stack head pointer.
 * @l_count: line count.
 * Return: always none.
 */
void pop(stack_t **head, unsigned int l_count)
{
	stack_t *rmv;

	if (!head || !(*head))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_count);
		exit(EXIT_FAILURE);
	}
	rmv = *head;
	*head = (*head)->next;
	if (!*head)
		return;
	(*head)->prev = NULL;
	rmv->next = NULL;
	free(rmv);
}
