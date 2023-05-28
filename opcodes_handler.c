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
		handle_error(*stack);
	}
	num = _atoi(arg, *stack, line_number);
	pointer = malloc(sizeof(stack_t));
	if (pointer == NULL)
	{
		perror("Error: malloc failed\n");
		handle_error(*stack);
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
/**
 * pint - Prints value at the top of stack
 * @stack: head of stack
 * @line_number: line number of command
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		handle_error(*stack);
	}
	printf("%d\n", top->n);
}
/**
 * pop - Removes the top element of stack
 * @stack: head of stack
 * @line_number: line number of command
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		handle_error(*stack);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
/**
 * swap - Swap the two top elements of a stack
 * @stack: pointer to head of stack
 * @line_number: line number of command
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int count = 0;

	count = count_nodes(temp);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		handle_error(*stack);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->prev = *stack;
	temp->next = (*stack)->next;
	if (temp->next != NULL)
		temp->next->prev = temp;
	(*stack)->next = temp;
}

