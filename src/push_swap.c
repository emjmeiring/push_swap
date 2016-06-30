
#include "checker.h"
//#include "push_swap.h"
/*

• The goal is to sort the stack with the minimum possible number of operations.
During defence we’ll compare the number of instructions your program found with
a maximum number of operation tolerated. If your program either displays a list
too big or if the list isn’t sorted properly, you’ll get no points.
• In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.
*/


/* display a list of instructions possible to sort the stack
a, the smallest number being at the top.
• Instructions must be separaed by a ’\n’ and nothing else.
*/
void	set_instr(char **instr)
{
	instr[0] = "ra";
	instr[1] = "sa";
	instr[2] = "pb";
	instr[3] = "ra";
	instr[4] = "\0\0\0";
}

/*push_swap ,arguments of integers.*/
int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int i;
	char **instr;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	stack_new(a, argc);
	stack_new(b, argc);
	instr = (char **)malloc(sizeof(char *) * 20);
	i = 0;
	if (argc <= 1)
		return (0);
	else if (!init_stacks(a, b, argc, argv))
			return (0);
	set_instr(instr);
	while (instr[i][0] != '\0')
	{
		write(1, instr[i], ft_strlen(instr[i]));
		write(1, "\n", 1);
		i++;
	}
	stack_dispose(a);
	stack_dispose(b);
	free(instr);
	return (0);
}
