#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *i;
	struct node *next;
} node;
typedef struct
{
	node *head;
	node *tail;
} queue;
void init_queue(queue *h)
{
        h->head = NULL;
        h->tail = NULL;
}
int push(queue *h, char *s)
{
	node *new;
	new = malloc(sizeof(node));
	new->i = s;
	new->next = NULL;
	if (h->tail != NULL)
		h->tail->next = new;
	h->tail = new;
	if (h->head == NULL)
		h->head = new;
	return (1);
}
char *pop(queue *h)
{
	if (h->head == NULL)
		return ("empty");
	node *tmp = h->head;
	char *result = tmp->i;
	h->head = h->head->next;
	if (h->head == NULL)
		h->tail = NULL;
	free(tmp);
	return (result);
}
int main(int argc, char **argv)
{
	queue h;
	int i = 2;
	char t;

	init_queue(&h);
	if (strcmp(argv[1], "push") == 0)
	{
		printf("%s\n", "push");
		while (i < argc)
		{
			push(&h, argv[i]);
			i++;
		}
	}
	while ((t = pop(&h)) != "empty")
	{
		printf("%s\n", t);
	}
	return (0);
}
