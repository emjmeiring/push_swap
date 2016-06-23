#include "push_swap.h"
#include <stdio.h>

int		main()
{
	t_stack	*s;
	t_stack	*s1;
	int		j;

	j = 0;
	s1 = (t_stack *)malloc(sizeof(t_stack));
	s = (t_stack *)malloc(sizeof(t_stack));
	stack_new(s);
	stack_new(s1);
	s->elems[0] = 5;
	s->elems[1] = 8;
	s->elems[2] = 6;
	s->elems[3] = 3;
	s->elems[4] = 1;
	s->elems[5] = 2;
	s->log_len = 6;


	//Swap two
	j = s->log_len - 1;
	printf("Testing Swap\n");
	while(j >= 0)
	{
		printf("%d\n", s->elems[j--]);
	}
	printf("After Swapping:\n");
	swap(s);
	j = s->log_len - 1;
	while(j >= 0)
	{
		printf("%d\n", s->elems[j--]);
	}

	//Shift Up
	j = s->log_len - 1;
	printf("\n\nTesting Shift-Up:\n");
	while(j >= 0)
	{
		printf("%d\n", s->elems[j--]);
	}
	printf("After shifting up:\n");
	shift_up(s);
	j = s->log_len - 1;
	while(j >= 0)
	{
		printf("%d\n", s->elems[j--]);
	}
	//end Shift Up
	
	//Shift Down
	j = s->log_len - 1;
	printf("\n\nTesting Shift-Down:\n");
	while(j >= 0)
	{
		printf("%d\n", s->elems[j--]);
	}
	printf("After Shifting Down:\n");
	shift_down(s);
	j = s->log_len - 1;
	while(j >= 0)
	{
		printf("%d\n", s->elems[j--]);
	}
	//end shift down
	
	//Push on
	j = s->log_len - 1;
	printf("\n\nTesting Push on:\n");
	while(j >= 0)
	{
		printf("%d\n", s->elems[j--]);
	}
	printf("After Push on:\n");
	stack_push_on(s1, s);
	j = s->log_len - 1;
	while(j >= 6)
	{
		printf("%d\n", s1->elems[j--]);
	}
	//end push on
	return (0);
	
	
	
}
