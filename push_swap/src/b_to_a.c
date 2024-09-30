/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:14:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/09 17:25:02 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	new_value_a(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	int	index;
	int	size;
	int	search;

	moves->moves->ra = 0;
	moves->moves->rra = 0;
	size = list_size(*stack_a);
	search = search_in(stack_a, (*stack_b)->value, 1 , size);
	index = count_r(*stack_a, search);
	if ((*stack_a)->value != search)
	{
		rra_or_ra(moves, size, index);
	}
	do_moves(stack_a, stack_b, moves, 1);
}

static void	new_order_max(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	int	size;
	int	index;

	moves->moves->ra = 0;
	moves->moves->rra = 0;
	size = list_size(*stack_a);
	index = count_r(*stack_a, get_highest(*stack_a)->value);
	if (tail(*stack_a)->value != get_highest(*stack_a)->value)
	{
		rra_or_ra(moves, size, index);
	}
	do_moves(stack_a, stack_b, moves, 1);
}

static void	new_order_min(t_lst **a, t_lst **b, t_moves *moves, int flag)
{
	int	size;
	int	index;

	size = list_size(*a);
	index = count_r(*a, get_lowest(*a)->value);
	moves->moves->ra = 0;
	moves->moves->rra = 0;
	if ((*a)->value != get_lowest(*a)->value)
	{
		rra_or_ra(moves, size, index);
	}
	do_moves(a, b, moves, flag);
}

void	sort2(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	while (*stack_b != NULL)
	{
		if ((*stack_b)->value < get_lowest((*stack_a))->value)
		{
			new_order_min(stack_a, stack_b, moves, 1);
		}
		else if ((*stack_b)->value > get_highest((*stack_a))->value)
		{
			new_order_max(stack_a, stack_b, moves);
		}
		else
		{
			new_value_a(stack_a, stack_b, moves);
		}
	}
	new_order_min(stack_a, stack_b, moves, 0);
}
