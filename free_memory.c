#include "monty.h"
/**
 * free_stack - Function that frees a stack
 * @head: head of stack
 *
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
/**
 * handle_error - Handles error cases
 * @line: A command of file
 * @stack: Stack to be freed
 *
 */
void handle_error(char *line, stack_t *stack)
{
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
