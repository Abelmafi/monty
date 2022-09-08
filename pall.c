#include "monty.h"
/**
 * _print - print linked list.
 * @head: linked liat head pointer.
 *
 * Return: number of nodes.
 */
size_t _print(const stack_t *head)
{
	/*const stack_t *current = head;*/
	size_t i = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * pall -  prints all the values on the
 * stack, starting from the top of the stack.
 * @head: linked list head pointer
 * @l_count: line count.
 * Return: always none.
 */
void pall(stack_t **head, unsigned int l_count __attribute__((unused)))
{
	_print(*head);
}
