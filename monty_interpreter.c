#include "monty.h"
/**
 * mul - multiplies the second top element with the top element of stack
 * @stack: Pointer to head of stack
 * @line_number: line number of command
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int count = 0, product = 1;

	count = count_nodes(*stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		handle_error(*stack);
	}
	top = *stack;
	second = (*stack)->next;
	product = second->n * top->n;
	pop(stack, line_number);
	(*stack)->n = product;
}
/**
 * mod - calculates remainder of two elements of a stack
 * @stack: Pointer to head of stack
 * @line_number: line number of command
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int count = 0, remainder = 1;

	count = count_nodes(*stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		handle_error(*stack);
	}
	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by 0\n", line_number);
		handle_error(*stack);
	}
	second = (*stack)->next;
	remainder = second->n % top->n;
	pop(stack, line_number);
	(*stack)->n = remainder;
}
