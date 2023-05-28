#include "monty.h"
/**
 * _atoi - convert a string to an integer.
 * @s: the string to be comverted.
 * @head: head of stack
 * @line_number: line number of command
 * Return: The integer value of the converted string.
 * -1 if string cannot be converted or if it contains strings
 */
int _atoi(char *s, stack_t *head, unsigned int line_number)
{
	int i, len, sign = 1, result = 0;

	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			if (i == 0 && s[i] == '-')
			{
				sign = -1;
				continue;
			}
			break;
		}
		result = result * 10 + (s[i] - '0');
	}
	if (i < len)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		handle_error(head);
	}
	return (result * sign);
}
