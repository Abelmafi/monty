#include "monty.h"
/**
 * parse_lines - split lines into diffrent strings.
 * @line: line to be slited.
 *
 * Return: splited string pointer.
 */
char **parse_lines(char *line)
{
	int bufsize = 100, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "lsh:kjljldkjljds\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " \t\n");
	}
	tokens[position] = NULL;
	return (tokens);
}
