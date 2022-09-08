#include "monty.h"
/**
 * _div - adds the top two elements of the stack.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always none.
 */
void _div(stack_t **head, unsigned int l_count)
{
	stack_t *tmp = *head;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_count);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_count);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	(*head)->n /= tmp->n;
	pop(&tmp, l_count);
}
