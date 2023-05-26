#include "monty.h"
/**
 * main - Entry point for the Monty ByteCode Interpreter
 * @argc: Argument count
 * @argv: Pointer to each element in argument
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fp, instructions);
	fclose(fp);
	return (0);
}
