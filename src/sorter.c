#include "push_swap.h"

void	push_all_to_a_because_is_sorted_in_b(t_stack *b, t_stack *a)
{
	stack_push_on(a, b);
}

void		find_min_ava_max(t_stack *a, int *min, int *ava, int *max)
{
	int			i;
	int			elem;
	long int	total;

	i = -1;
	total = 0;
	*min = a->elems[0];
	while (++i < a->log_len)
	{
		elem = a->elems[i];
		if (elem > *max)
			*max = elem;
		if (elem < *min)
			*min = elem;
		total += elem;
	}
	*ava = total / i;
}

int		is_decsending(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->log_len)
	{
		if (a->elems[i] <= a->elems[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		is_sorted(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->log_len)
	{
		if (a->elems[i] >= a->elems[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void		myne_sorter(t_stack *a, t_stack *b, char **instr)
{
	int		min;
	int		ava;
	int		max;
	int		i;
	//int		shifted;
//	int k = 0;

	i = 0;
	min = 0;
	ava = 0;
	max = 0;
	//shifted = 0;
	find_min_ava_max(a, &min, &ava, &max);
	printf("%d\t%d\t%d\n", min, ava, max);
	stack_push_on(b, a);
	instr[i++] = "pb";
	while (!is_sorted(a) && i < 200)
	{
		if (a->elems[a->log_len - 1] >= a->elems[a->log_len - 2])
		{
			stack_push_on(b, a);
			instr[i++] = "pb";
			if (b->elems[b->log_len - 1] < b->elems[b->log_len - 2])
			{
				swap(b);
				instr[i++] = "sb";
			
				//stack_push_on(a, b);
				//instr[i++] = "pa";k++;
				//shift_up(a);
				//instr[i++] = "ra";k++;
			}
		}else
		{
			shift_up(a);
			instr[i++] = "ra";
		}
		while (!is_decsending(b) && b->log_len != 0)
		{
			stack_push_on(a, b);
			instr[i++] = "pa";
			shift_up(a);
			instr[i++] = "ra";
		}
	}
	instr[i++] = "\0\0";
		//if (b->log_len == 0 && is_sorted(a))
			//return ;
		//else
		//{
			/*while ((a->log_len - b->log_len) >= 1 || shifted < a->log_len)
			{
				if (a->elems[a->log_len-1] <= ava)
				{
					stack_push_on(b, a);
					instr[i++] = "pb"; k++;
					if (a->elems[a->log_len - 1] < a->elems[a->log_len - 2])
					{
						if (b->log_len >= 2)
						{
							if(b->elems[b->log_len - 1] < b->elems[b->log_len - 2])
							{
								instr[i++] = "ss";k++;
								swap(a);
								swap(b);
							}
							else
							{
								swap(a);
								instr[i++] = "sa";k++;
							}
						}else
						{
							swap(a);
							instr[i++] = "sa";k++;
						}
					}else if(b->elems[b->log_len - 1] < b->elems[b->log_len - 2])
					{
						swap(b);
						instr[i++] = "sb";k++;
					}
				}
				else
				{
					shifted++;
					shift_up(a);
					instr[i++] = "ra";k++;
				}
			}
			instr[i++] = "\0\0";k++;
*/			//while (
//		}
	//}
	//while (b->log_len == 0)
	//	push_all_to_a_because_is_sorted_in_b(b, a);
		
//	return (42);
}
