#define  _GNU_SOURCE
#include "monty.h"
int status = 0;
/**
 *
 *
 *
 */
/*void pall(stack_t **head, unsigned int l_count __attribute__((unused)))
{
        stack_t *print = *head;

        while (print != NULL)
        {
                printf("%d\n", print->n);
                print = print->next;
        }
}*/
/**
 *
 *
 *
 *
 *
 *
 */

void pint(stack_t **head, unsigned int l_count)
{
	if (!head || !(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_count);
	}
	printf("%d\n", (*head)->n);
}
/**
 *
 *
 *
 *
 */
void pop(stack_t **head, unsigned int l_count)
{
	stack_t *rmv;

	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_count);
		exit(EXIT_FAILURE);
	}
	rmv = *head;
	*head = (*head)->next;
	if (!*head)
		return;
	(*head)->prev = NULL;
	rmv->next = NULL;
	free(rmv);
}
/**
 *
 *
 *
 *
 */
void swap(stack_t **head, unsigned int l_count)
{
	stack_t *tmp = NULL, *current = *head;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_count);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	current->next = tmp->next;
	current->prev = tmp;
	tmp->next = current;
	tmp->prev = NULL;
	*head = tmp;
}
/**
 *
 *
 *
 *
 *
 */
void add(stack_t **head, unsigned int l_count)
{
	stack_t *tmp = *head;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_count);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	(*head)->n += tmp->n;
	pop(&tmp, l_count);
}
/*void exec_line(stack_t **head, char **args, unsigned int l_count)
{
	unsigned int i;
	instruction_t f_list[] = INSTRUCTIONS;

	for (i = 0; f_list[i].opcode != NULL; i++)
	{
		if (strcmp(args[0], f_list[i].opcode) == 0)
		{
			f_list[i].f(head, l_count);
			return;
		}
	}
}*/
/**
 *
 *
 *
 */
/*void read_line(FILE *fh_output, stack_t **head)
{
	char *line = NULL;
	size_t bufsize = 0;
	char **args;
	unsigned int l_count = 0;

	while (getline(&line, &bufsize, fh_output) != -1)
	{
		if (status)
			break;
		if (*line == '\n')
		{
			l_count++;
			continue;
		}
		args = parse_lines(line);
		global.c = args[1];
		if (!args || args[0] == "#")
		{
			l_count++;
			continue;
		}
		exec_line(head, args, l_count);
		l_count++;
	}
	free(line);
}*/
void f_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
void u_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
int main(int argc, char **argv)
{
	FILE *fh_output;
	stack_t *head = NULL;

	if (argc != 2)
		u_error();
	fh_output = fopen(argv[1], "r");
	if (!fh_output)
		f_error(argv[1]);
	read_line(fh_output, &head);

	fclose(fh_output);
	exit(EXIT_SUCCESS);
}

