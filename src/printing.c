#include "checker.h"

int		init_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*(a->elems + argc - 1) = 0;
	*(b->elems + argc - 1) = 0;
	while (argc > 1)
	{
		while (argv[argc - 1][j])
		{
			if (!ft_isdigit(argv[argc - 1][j]))
			{
				write(1, "Error", 5);
				return (0);
			}
			j++;
		}
		stack_push(a, ft_atoi(argv[argc - 1]));		
		b->elems[i] = 0;
		i++;
		argc--;
	}
	return (1);
}

void	print_stacks(t_stack *a, t_stack *b, int i, char **instr)
{
	while (i >= 0)
	{
		if (i == (a->log_len - 1) || i == (b->log_len -1 ))
			printf(">");
		printf("%d\t%s  |\n", *(a->elems + i), *(b->elems + i) == 0 ? " " : ft_itoa(b->elems[i]));
		i--;
	}
	printf("-\t-  |\na\tb  |\n");
	i=0;
	while (instr[i])
	{
		printf("%s\n", instr[i]);
		i++;
	}
}
