#include "monty.h"
/**
 * push - Pushes a number to stack
 * @stack: head of the stack
 * @line_number: line number of the command
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num;
	char *arg;
	stack_t *pointer;

	arg = strtok(NULL, " \t");
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		handle_error(line, *stack);
	}
	num = _atoi(arg);
	if (!num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		handle_error(line, *stack);
	}
	pointer = malloc(sizeof(stack_t));
	if (pointer == NULL)
	{
		perror("Error: malloc failed\n");
		handle_error(line, *stack);
		exit(EXIT_FAILURE);
	}
	pointer->n = num;
	pointer->next = *stack;
	pointer->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = pointer;
	*stack = pointer;
}
/**
 * pall - Prints members of stack
 * @stack: head of the stack
 * @line_number: line number of command
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
