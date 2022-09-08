#include "monty.h"
/**
 * _mul - adds the top two elements of the stack.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always none.
 */
void _mul(stack_t **head, unsigned int l_count)
{
	stack_t *tmp = *head;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_count);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	(*head)->n *= tmp->n;
	pop(&tmp, l_count);
}
