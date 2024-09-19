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

static void	do_moves(t_lst **stack_a, t_lst **stack_b, t_moves *moves, int push)
{
	while (moves->moves->rra-- != 0)
		reverse_rotate_a(stack_a);
	while (moves->moves->ra-- != 0)
		rotate_a(stack_a);
	if (push == 1)
		push_a(stack_a, stack_b);
}

static int	search_in_a(t_lst **stack_a, int b_value)
{
	t_lst	*tmp;
	int		i;
	int		size;
	int		flag;

	i = 0;
	flag = 0;
	tmp = *stack_a;
	size = list_size(*stack_a);
	while(flag == 0 || tmp != NULL)
	{
		i = 0;
		tmp = *stack_a;
		b_value++;
		while(i++ < size)
		{
			// ft_printf("here\n");
			if (tmp->value == b_value)
				flag = 1;
			tmp = tmp->next;
		}
	}
	return (b_value);
}

static void	new_value_a(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	int	index;
	int	size;
	int	search;

	moves->moves->ra = 0;
	moves->moves->rra = 0;
	size = list_size(*stack_a);
	search = search_in_a(stack_a, (*stack_b)->value);
	index = count_r(*stack_a, search);
	if ((*stack_a)->value != search)
	{
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				moves->moves->rra = (size - index);
			else
				moves->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				moves->moves->rra = size - index;
			else
				moves->moves->ra = index;
		}
	}
	// add reverse or rotate function here
	// apply moves and check for push
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
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				moves->moves->rra = (size - index) - 1;
			else
				moves->moves->ra = index + 1;
		}
		else
		{
			if (index > size / 2)
				moves->moves->rra = (size - index) - 1;
			else
				moves->moves->ra = index + 1;
		}
	}
	// add reverse or rotate function here
	//apply moves and check for push
	do_moves(stack_a, stack_b, moves, 1);
}

static void	new_order_min(t_lst **stack_a, t_lst **stack_b, t_moves *moves, int flag)
{
	int	size;
	int	index;

	size = list_size(*stack_a);
	index = count_r(*stack_a, get_lowest(*stack_a)->value);
	moves->moves->ra = 0;
	moves->moves->rra = 0;
	if ((*stack_a)->value  != get_lowest(*stack_a)->value)
	{
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				moves->moves->rra = size - index;
			else
				moves->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				moves->moves->rra = size - index;
			else
				moves->moves->ra = index;
		}
	}
	// add reverse or rotate function here
	//apply moves and check for push
	do_moves(stack_a, stack_b, moves, flag);
}

void	sort2(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	while (*stack_b != NULL)
	{
		if ((*stack_b)->value < get_lowest((*stack_a))->value)
		{
			// ft_printf("1 \n");
			new_order_min(stack_a, stack_b, moves, 1);
		}
		else if((*stack_b)->value > get_highest((*stack_a))->value)
		{
			// ft_printf("2 \n");
			new_order_max(stack_a, stack_b, moves);
			// rotate_a(stack_a);
		}
		else
		{
			// ft_printf("3 \n");
			new_value_a(stack_a, stack_b, moves);
		}
	}
	// ft_printf("here?\n");
	new_order_min(stack_a, stack_b, moves, 0);
}
