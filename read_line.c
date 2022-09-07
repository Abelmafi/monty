#include "monty.h"
/**
 *
 *
 *
 *
 *
 */
void read_line(FILE *fh_output, stack_t **head)
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
}

