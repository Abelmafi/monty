#include "monty.h"
/**
 *
 *
 *
 *
 */
void exec_line(stack_t **head, char **args, unsigned int l_count)
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
}

