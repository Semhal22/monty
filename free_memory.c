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
