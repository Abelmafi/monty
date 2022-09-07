#define  _GNU_SOURCE
#include "monty.h"
/**
 *
 *
 *
 */
void pall(stack_t **head, unsigned int no)
{
        stack_t *print = *head;
        (void)no;

        while (print != NULL)
        {
                printf("%d\n", print->n);
                print = print->next;
        }
}
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
	printf("%d\n", top->n);
}
/**
 *
 *
 *
 *
 */
void pop(stack_t **head, unsigned int no)
{
	stack_t *rmv;
	(void)no;

	if (*head == NULL)
		fprintf(stderr, "kjhkjhk");
	rmv = *head;
	*head = (*head)->next;
	rmv->next = NULL;
	free(rmv);
}
/**
 *
 *
 *
 *
 */
void swap(stack_t **head, unsigned int no)
{
	stack_t *tmp, *current = *head;
	(void)no;

	if ((*head)->next == NULL)
		fprintf(stderr, "hifjfj");
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
void add(stack_t **head, unsigned int no)
{
	stack_t *tmp = *head;
	(void)no;

	if ((*head)->next == NULL)
		fprintf(stderr, "jljl");
	*head = (*head)->next;
	(*head)->n += tmp->n;
	pop(&tmp, no);
}
/**
 *
 *
 *
 */
void read_line(FILE *fh_output, stack_t **head)
{
	char *line = NULL;
	size_t bufsize = 0;
	char **args;
	unsigned int num, i;
	instruction_t f_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	while (getline(&line, &bufsize, fh_output) != -1)
	{
		args = parse_lines(line);
		(args[1] == NULL) ? args[1] = "0" : args[1];
		for (i = 0; f_list[i].opcode != NULL; i++)
		{
			if (strcmp(args[0], f_list[i].opcode) == 0)
			{
				num = atoi(args[1]);
				f_list[i].f(head, num);
			}
		}
	}
}

int main(int argc, char **argv)
{
	FILE *fh_output;
	stack_t *head = NULL;

	(void)argc;
	fh_output = fopen(argv[1], "r");
	read_line(fh_output, &head);

	fclose(fh_output);
	return (0);
}



