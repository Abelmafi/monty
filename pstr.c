#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always nothing.
 */
void pstr(stack_t **head, unsigned int l_count)
{
	stack_t *current = *head;

	if (!head || !(*head))
		printf("\n");
	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
