#include "push_swap.h"

/**
 * A set of functions to manipulate a stack of integers
 **/

void		stack_grow(t_stack *s)
{
	int		temp[s->log_len];

	memcpy(temp, s->elems, s->log_len);
	s->elems = (int *)malloc(s->alloc_len * sizeof(int));
	memcpy(s->elems, temp, s->log_len);
}

void			stack_new(t_stack *s)
{
	s->log_len = 0;
	s->alloc_len = 6;
	s->elems = malloc(6 * sizeof(int));
	//s->log_len = 6;
	assert(s->elems != NULL);
}

void			stack_dispose(t_stack *s)
{
	free(s->elems);
}

void			stack_push(t_stack *s, int val)
{
	if (s->alloc_len == s->log_len)
	{
		s->alloc_len *= 2;
		stack_grow(s);
	}
	s->elems[s->log_len] = val;
	s->log_len++;
}

int				stack_pop(t_stack *s)
{
	if (s->log_len > 0)
		s->log_len--;
	return (s->elems[s->log_len]);		
}



