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
 * @stack: Stack to be freed
 *
 */
void handle_error(stack_t *stack)
{
	free(global.line);
	free_stack(stack);
	fclose(global.fp);
	exit(EXIT_FAILURE);
}
