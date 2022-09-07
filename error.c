#include "monty.h"
/**
 * f_error - print error message for any reason, it’s
 * not possible to open the file
 * @argv: argument vector.
 *
 * Return: always none
 */
void f_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * u_error - print error message If the user does not give any file
 * or more than one argument to your program
 *
 * Return: always none.
 *
 */
void u_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

