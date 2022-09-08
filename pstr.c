#include "monty.h"
#include <stdlib.h>
/**
 * pstr - prints the string starting at the top of the stack.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always nothing.
 */
void pstr(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	while (*head)
	{
		if ((*head)->n <= 0 || (*head)->n > 127)
			break;
		putchar((char) (*head)->n);
		*head = (*head)->next;
	}
	putchar('\n');
}
