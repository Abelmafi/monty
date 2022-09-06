#include "monty.h"
/**
 *
 *
 *
 *
 *
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
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);
}
