#define  _GNU_SOURCE
#include "monty.h"
/**
 * read_line - read line from file
 * @head: linked list head.
 * @fh_output: file input.
 *
 * Return: always none.
 */
void read_line(FILE *fh_output, stack_t **head)
{
	char *line = NULL;
	size_t bufsize = 0;
	char **args;
	unsigned int l_count = 0;

	while (getline(&line, &bufsize, fh_output) != -1)
	{
		if (*line == '\n')
		{
			l_count++;
			continue;
		}
		args = parse_lines(line);
		global.c = args[1];
		if (!args)
		{
			l_count++;
			continue;
		}
		exec_line(head, args, l_count);
		l_count++;
	}
	free(line);
}
