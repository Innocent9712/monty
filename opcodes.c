#include "monty.h"
/**
 * get_op_func - get the function for a corresponding command
 * @cmd: command to check with
 *
 * Return: 0 always
 */

int get_op_func(char *cmd)
{
	unsigned int i = 0;
	instruction_t funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (funcs[i].opcode)
	{
		if (strcmp(funcs[i].opcode, cmd) == 0)
		{
			funcs[i].f(&my_glob_vars.head, my_glob_vars.line_num);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
		my_glob_vars.line_num, cmd);
	exit(EXIT_FAILURE);
}
