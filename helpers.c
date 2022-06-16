#include "monty.h"

/**
 * is_valid_num - checks if value is a number
 * @str: the string to convert
 *
 * Return: 1 for success and 0 for failure
 */

int is_valid_num(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}
