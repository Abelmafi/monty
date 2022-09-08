#include "monty.h"
#include <ctype.h>
/**
 * _isalpha - check number if its alpha bet.
 * @c: ascii value input.
 *
 * Return: length of string.
 */

int _isalpha(int c)
{
	return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @head: linked list head pointer.
 * @l_count: line count.
 * Return: always none.
 */
void pchar(stack_t **head, unsigned int l_count)
{
	int s;

	if (!head || !(*head))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", l_count);
		exit(EXIT_FAILURE);
	}
	s = (*head)->n;
	if (_isalpha(s) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_count);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", s);
}
