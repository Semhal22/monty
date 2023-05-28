#include "monty.h"
/**
 * count_nodes - counts nodes in a stack
 * @head: head of the stack
 *
 * Return: no of codes
 */
int count_nodes(stack_t *head)
{
	stack_t *temp = head;
	int count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
/**
 * add - adds the top two elements of the stack
 * @stack: head of stack
 * @line_number: line number of command
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int count = 0, sum = 0;

	count = count_nodes(*stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		handle_error(*stack);
	}
	temp = *stack;
	count = 0;
	while (count < 2)
	{
		sum += temp->n;
		temp = temp->next;
		count++;
	}
	pop(stack, line_number);
	(*stack)->n = sum;
}
/**
 * nop - doesn't do anything
 * @stack: Pointer to head of stack
 * @line_number: line number of command
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * sub - subracts the top element from the second top element
 * @stack: Pointer to head of stack
 * @line_number: line number of command
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int count = 0, diff = 0;

	count = count_nodes(*stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		handle_error(*stack);
	}
	temp = *stack;
	count = 0;
	while (count < 2)
	{
		diff = temp->n - diff;
		temp = temp->next;
		count++;
	}
	pop(stack, line_number);
	(*stack)->n = diff;
}
/**
 * divide - divides the second top element by the top element of stack
 * @stack: Pointer to head of stack
 * @line_number: line number of command
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int count = 0, quotient = 1;

	count = count_nodes(*stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		handle_error(*stack);
	}
	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		handle_error(*stack);
	}
	second = (*stack)->next;
	quotient = second->n / top->n;
	pop(stack, line_number);
	(*stack)->n = quotient;
}
