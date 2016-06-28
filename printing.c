#include "checker.h"

int		init_stacks(int *a, int *b, int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
		*(a + i) = ft_atoi(argv[argc - 1]);
		*(b + i) = 0;
		i++;
		argc--;
	}
	return (1);
}

void	print_stacks(int *a, int *b, int i, char **instr)
{
	while (i >= 0)
	{
		printf("%d\t%s  |\n", *(a + i), *(b + i) == 0 ? " " : ft_itoa(b[i]));
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
