#include "monty.h"
/**
 * _atoi - convert a string to an integer.
 * @s: the string to be comverted.
 * Return: The integer value of the converted string.
 * -1 if string cannot be converted or if it contains strings
 */
int _atoi(char *s)
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
		return (0);
	else
		return (result * sign);
}
