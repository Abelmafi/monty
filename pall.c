#include "monty.h"
/**
 *
 *
 *
 *
 *
 */
void pall(stack_t **head, unsigned int l_count __attribute__((unused)))
{
        stack_t *print = *head;

        while (print != NULL)
        {
                printf("%d\n", print->n);
                print = print->next;
        }
}
