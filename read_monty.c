#include "monty.h"
char *line = NULL;
/**
 * read_file - Reads a file
 * @fp: pointer to the file
 * @instructions: array of instructions
 *
 * Return: 0
 */
int read_file(FILE *fp, instruction_t instructions[])
{
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	char *opcode;
	int found, i, line_number = 0;

	while ((bytes_read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';
		if (!line)
			break;
		found = 0;
		opcode = strtok(line, " \t");
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
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_stack(stack);
	return (0);
}
