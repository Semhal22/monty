#include "monty.h"
/**
 * read_file - Reads a file
 * @instructions: array of instructions
 *
 * Return: 0
 */
int read_file(instruction_t instructions[])
{
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	char *opcode;
	int found, i, line_number = 0;

	while ((bytes_read = getline(&(global.line), &len, global.fp)) != -1)
	{
		line_number++;
		global.line[strcspn(global.line, "\n")] = '\0';
		if (!global.line)
			continue;
		found = 0;
		opcode = strtok(global.line, " \t");
		if (opcode[0] == '#')
		{
			nop(&stack, line_number);
			continue;
		}
		if (!opcode)
			continue;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(instructions[i].opcode, opcode) == 0)
			{
				found = 1;
				instructions[i].f(&stack, line_number);
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
	return (0);
}
