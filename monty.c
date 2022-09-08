#include "monty.h"
/**
 * main - an interpreter for Monty ByteCodes files.
 * @argc: argument vectors count
 * @argv: argument vetctor.
 * Return: always none.
 *
 */
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
	free_stack(head);
	exit(EXIT_SUCCESS);
}
