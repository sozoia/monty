#include "monty.h"

/**
 * parse - parse
 * @line: line
 * Return: arr of ptr
*/
char **parse(char *line)
{
	int len = 0, cap = ARGBUF;
	char *token = NULL, **tokens;

	tokens = malloc(cap * sizeof(char *));
	if (!tokens)
	{
		len = strlen("tokenatioan failed");
		write(STDERR_FILENO, "tokenatioan failed", len);
		return (NULL);
	}
	token = strtok(line, DELIMIT);

	if (check(token) == -1)
	{
		return (NULL);
	}

	while (token)
	{
		tokens[len++] = token;
		if (len >= cap)
		{
			cap += (ARGBUF + 1);
			tokens = realloc(tokens, cap * sizeof(char *));
			if (!tokens)
			{
				len = strlen("tokenatioan failed at mid");
				write(STDERR_FILENO, "tokenatioan failed at mid", len);
				return (NULL);
			}
		}
		token = strtok(NULL, DELIMIT);
	}
	tokens[len] = NULL;
	return (tokens);
}

/**
 * check - check if the order is rigth
 * @order: is the command
 * return: 0 if ture else -1
 */
int check(char *order)
{
	char *arr[4] = {"push", "pall", "pint", "pop"};
	int i, len;

	len = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < len; i++)
	{
		if (strcmp(arr[i], order) == 0)
			return (0);
	}
	return (-1);
}

/**
 * excute - excute the command
 * @order: command
 * Return: 0 if success else -1
*/
int excute(char **order)
{
	int i = 0, len;

	if (order[1] != NULL)
		i = atoi(order[1]);

	if (strcmp(order[0], "push") == 0)
	{
		if (!order[1])
		{
			len = strlen("L<line_number>: usage: push integer");
			write(STDERR_FILENO, "L<line_number>: usage: push integer", len);
			return (EXIT_FAILURE);
		}
		push(i);
	}
	else if (strcmp(order[0], "pall") == 0)
	{
		pall();
	}
	else if (strcmp(order[0], "pint") == 0)
		pint();
	else if (strcmp(order[0], "pop") == 0)
		pop();
	else
		printf("Default case or error handling\n");

	return (0);
}
