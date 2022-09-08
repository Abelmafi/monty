#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define INSTRUCTIONS	\
	{		\
		{"push", push},	\
		{"pall", pall},	\
		{"pint", pint},	\
		{"pop", pop},	\
		{"swap", swap},	\
		{"add", _add},	\
		{"nop", nop},	\
		{"pchar", pchar},	\
		{"pstr", pstr},	\
		{		\
			NULL, NULL	\
		}	\
	}
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data - linked list node value handler.
 * @c: linked list data.
 *
 * Discription: stare data from file args opcode.
 */
typedef struct data
{
	char *c;
} data_s;

data_s global;

void exec_line(stack_t **head, char *args, unsigned int l_count);
void read_line(FILE *fh_output, stack_t **head);

void free_stack(stack_t *head);
extern stack_t *add_node(stack_t **head, int num);

void f_error(char *argv);
void u_error(void);

size_t _print(const stack_t *head);
int is_digit(char *str);

extern void pall(stack_t **head, unsigned int l_count);
extern void pint(stack_t **head, unsigned int l_count);
extern void push(stack_t **head, unsigned int l_count);
extern void pall(stack_t **head, unsigned int l_count);
extern void pop(stack_t **head, unsigned int l_count);
extern void swap(stack_t **head, unsigned int l_count);
extern void _add(stack_t **head, unsigned int l_count);
extern void nop(stack_t **head, unsigned int l_count);
extern void pchar(stack_t **head, unsigned int l_count);
extern void pstr(stack_t **head, unsigned int l_count);
#endif
