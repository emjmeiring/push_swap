/*
• If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" followed by a ’\n’ on the standard output. In every
other case, checker must display "KO" followed by a ’\n’ on the standard output.
• In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer, there are duplicates, an instruction don’t exist and/or is
incorrectly formatted.
*/
#include "checker.h"

/*• wait and read instructions , each instruction will be followed by ’\n’.
* checker execute instructions e stack received as an argument.*/
int		read_instr(char **instr)
{
	int i;
	int nbytes;
	char *line;

	i = 0;
	nbytes = 0;
	line = (char *)malloc(sizeof(char) * 6);
	
	while ((nbytes = get_next_line(0, &line)) && i < 20)// && *line != '1')
	{
		instr[i] = ft_strdup(line);
		i++;
	}
	if (i == 20)
	{
		write(1, "Too many instructions\n", 22);
		ft_memdel((void **)&line);
		return(-3);
	}
	//instr[i] = ft_strdup("1");
	//write(1, "ass",3);
	ft_memdel((void **)&line);
	return (nbytes);
}
/*
• argument is a stack of integers, first at the top of stack. --done
* If no argument is given checker stops and displays nothing. --done*/
int		main(int argc, char **argv)
{
	int *a;
	int *b;
	int i;
	char **instr;

	a = (int *)malloc(sizeof(int) * argc);
	b = (int *)malloc(sizeof(int) * argc);
	instr = (char **)malloc(sizeof(char *) * 20);
	i = argc - 2;
	if (argc <= 1)
		return (0);
	else if (!init_stacks(a, b, argc, argv))
			return (0);		
	if(read_instr(instr) != -3) /// need to change -3
	{
		//write(1, "woow", 4);
		//apply_instr(a, b, instr);
		print_stacks(a, b, i, instr);
	}
	free(a);
	free(b);
	ft_memdel((void **)instr);
	free(instr);
	return (0);
}
