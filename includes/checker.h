/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:58:44 by jomeirin          #+#    #+#             */
/*   Updated: 2016/06/13 09:53:19 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "push_swap.h"

int		init_stacks(t_stack *a, t_stack *b, int argc, char **argv);
void	print_stacks(t_stack *a, t_stack *b, int i, char **instr);
int		read_instr(char **instr);
#endif
