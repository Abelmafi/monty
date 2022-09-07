#include "monty.h"
/**
 *
 *
 *
 *
 *
 *
 */
void pint(stack_t **head, unsigned int no)
{
	stack_t *top = *head;
	(void)no;

	if (*head == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty");
	}
	printf("%s\n", top->n);
}

