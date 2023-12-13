#include "monty.h"

/**
 * push - push value onto stack
 * @element: value will be added
*/
void push(int element)
{
    stack_t *new = NULL;

    new = malloc(sizeof(stack_t));

    if (!new)
        fprintf(stderr, "memory problem");
    else
    {
        new->n = element;

        if (linked == NULL)
        {
            linked = new;
        }
        else
        {
            new->next = linked;
            new->prev = NULL;
            linked->prev = new;
            linked = new;
        }
    }
}


/**
 * pall - print the content of stack
*/
void pall()
{
	stack_t *temp = NULL;
	
	temp = linked;

	while (temp)
	{
		printf("%d\n",temp->n);

		if (temp)
			temp = temp->next;
	}
}

/**
 * pint - print the data at top of stack
*/
void pint()
{
	if (linked)
	{
		printf("%d\n",linked->n);
	}
	else
		fprintf(stderr, "L<line_number>: can't pint, stack empty");
}

void pop()
{
    stack_t *temp = NULL;

    if (linked)
    {
        if (!linked->next)
        {
            free(linked);
            linked = NULL;
        }
        else
        {
            linked = linked->next;
            temp = linked->prev;
            linked->prev = NULL;
            free(temp);
        }
    }
    else
        fprintf(stderr, "L<line_number>: can't pop an empty stack");
}
