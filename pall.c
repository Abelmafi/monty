#include "monty.h"
/**
 * pall -  prints all the values on the
 * stack, starting from the top of the stack.
 * @head: linked list head pointer
 * @l_count: line count.
 * Return: always none.
 */
void pall(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	stack_t *print = *head;

	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}
