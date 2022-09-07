#include "monty.h"
/**
 * exec_line - excute parsed comand lines with argumets
 * @head: stack head
 * @args: comand line arguments
 * @l_count: arguments line count
 *
 * Return: always none.
 */
void exec_line(stack_t **head, char *args, unsigned int l_count)
{
	unsigned int i;
	instruction_t f_list[] = INSTRUCTIONS;

	for (i = 0; f_list[i].opcode != NULL; i++)
	{
		if (strcmp(args, f_list[i].opcode) == 0)
		{
			f_list[i].f(head, l_count);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l_count, args);
	exit(EXIT_FAILURE);
}
