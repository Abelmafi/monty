#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @head: stack head pointer.
 * @l_count: line count.
 *
 * Return: always nothing.
 */
void pint(stack_t **head, unsigned int l_count)
{
	if (!head || !(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

