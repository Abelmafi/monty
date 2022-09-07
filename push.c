#include "monty.h"
#include <ctype.h>

/**
 * is_digit - check is the string holds only digit chars
 * @str: string input.
 * Return: 1 if its digit 0 if it's not.
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

/**
 * push - push int of data into the stack
 * @head: linked list head pointer.
 * @l_count: line count.
 *
 * Return: alwaya none.
 */
void push(stack_t **head, unsigned int l_count)
{
	char *s = global.c;

	if (is_digit(s) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_count);
		exit(EXIT_FAILURE);
	}
	if (!add_node(head, atoi(s)))
	{
		exit(EXIT_FAILURE);
	}
}
