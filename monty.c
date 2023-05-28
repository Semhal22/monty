#include "monty.h"
struct global_vars global = {NULL, NULL};
/**
 * main - Entry point for the Monty ByteCode Interpreter
 * @argc: Argument count
 * @argv: Pointer to each element in argument
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.fp = fopen(argv[1], "r");
	if (global.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(instructions);
	return (0);
}
