/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:57:27 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 17:57:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	double_moves(t_moves *moves)
{
	moves->moves->rr = 0;
	moves->moves->rrr = 0;
	while(moves->moves->ra > 0 && moves->moves->rb > 0)
	{
		moves->moves->ra--;
		moves->moves->rb--;
		moves->moves->rr++;
	}
	while(moves->moves->rra > 0 && moves->moves->rrb > 0)
	{
		moves->moves->rra--;
		moves->moves->rrb--;
		moves->moves->rrr++;
	}
}

static int	search_in_b(t_lst **stack_b, int a_value)
{
	t_lst 	*tmp;
	int		i;
	int		size;
	int		flag;

	i = 0;
	flag = 0;
	tmp = *stack_b;
	size = list_size(*stack_b);
	while(flag == 0 || tmp != NULL)
	{
		i = 0;
		tmp = *stack_b;
		a_value--;
		while(i++ < size)
		{
			if (tmp->value == a_value)
				flag = 1;
			tmp = tmp->next;
		}
	}
	return (a_value);
}

static void	new_element_b(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	int	index;
	int	size;
	int	search;

	moves->moves->rb = 0;
	moves->moves->rrb = 0;
	search = search_in_b(stack_b, (*stack_a)->value);
	if ((*stack_b)->value == search)
		return ;
	index = count_r(*stack_b, search);
	size = list_size(*stack_b);
	if (size % 2 == 0)
	{
		if (index + 1 > size / 2)
			moves->moves->rrb = size - index;
		else
			moves->moves->rb = index;
	}
	else
	{
		if (index > size / 2)
			moves->moves->rrb = size - index;
		else
			moves->moves->rb = index;
	}
}

static void	max_moves_in_b(t_lst **stack_b, t_moves *moves)
{
	int	index;
	int	size;

	moves->moves->rb = 0;
	moves->moves->rrb = 0;
	size = list_size(*stack_b);
	index = count_r(*stack_b, get_highest(*stack_b)->value);
	if (size % 2 == 0)
	{
		if (index + 1 > size / 2)
			moves->moves->rrb = size - index;
		else
			moves->moves->rb = index;
	}
	else
	{
		if (index > size / 2)
			moves->moves->rrb = (size - index);
		else
			moves->moves->rb = index;
	}
}

static void	to_top(t_lst **stack_a, t_lst *tmp, int i, t_moves *moves)
{
	int		size;

	moves->moves->pb = 1;
	moves->moves->ra = 0;
	moves->moves->rra = 0;
	if ((*stack_a)->value == tmp->value)
		return ;
	size = list_size(*stack_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			moves->moves->rra = (size - i);
		else
			moves->moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			moves->moves->rra = size - i;
		else
			moves->moves->ra = i;
	}
}

static void	cost(t_moves *moves, int i)
{
	moves->moves->total = moves->moves->ra + moves->moves->rb
		+ moves->moves->rr + moves->moves->rra + moves->moves->rrb
		+ moves->moves->rrr + moves->moves->pb;
	if (i == 1 || moves->moves->total < moves->cheapest->total)
	{
		moves->cheapest->total = moves->moves->total;
		moves->cheapest->ra = moves->moves->ra;
		moves->cheapest->rb = moves->moves->rb;
		moves->cheapest->rr = moves->moves->rr;
		moves->cheapest->rra = moves->moves->rra;
		moves->cheapest->rrb = moves->moves->rrb;
		moves->cheapest->rrr = moves->moves->rrr;
		moves->cheapest->pb = moves->moves->pb;
	}
}


static void	moving_cheapest(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	while(moves->cheapest->rr-- != 0)
		rotate_s(stack_a, stack_b);
	while(moves->cheapest->ra-- != 0)
		rotate_a(stack_a);
	while(moves->cheapest->rb-- != 0)
		rotate_b(stack_b);
	while(moves->cheapest->rrr-- != 0)
		reverse_rr(stack_a, stack_b);
	while(moves->cheapest->rra-- != 0)
		reverse_rotate_a(stack_a);
	while(moves->cheapest->rrb-- != 0)
		reverse_rotate_b(stack_b);
	while(moves->cheapest->pb-- != 0)
		push_b(stack_b, stack_a);
}

static void	move_to_b(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	int		size;
	int		i;
	t_lst	*tmp;

	size = list_size(*stack_a);
	i = 0;
	tmp = *stack_a;
	while (i++ < size)
	{
		to_top(stack_a, tmp, i - 1, moves);
		if (tmp->value > get_highest(*stack_b)->value || tmp->value < get_lowest(*stack_b)->value)
		{
			// ft_printf(" A = %d\n", i);
			max_moves_in_b(stack_b, moves);
		}
		else
		{
			// new_element_b(stack_a, stack_b, moves);
			new_element_b(&tmp, stack_b, moves);
		}
		double_moves(moves);
		cost(moves, i);
		tmp = tmp->next;
	}
}

static void cheapest(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	int	size;

	size = list_size(*stack_a);
	while(size > 3 || check_sort(*stack_a) != 1)
	{
		move_to_b(stack_a, stack_b, moves);
		moving_cheapest(stack_a, stack_b, moves);
		size--;
	}
	if (size == 3)
		sort_three(stack_a);
	sort2(stack_a, stack_b);
}

void	sort1(t_lst **stack_a, t_lst **stack_b)
{
	t_moves	*moves;

	moves = ft_calloc(1, sizeof(t_moves));
	if (!moves)
		return ;
	moves->cheapest = ft_calloc(1, sizeof(t_mov));
	moves->moves = ft_calloc(1, sizeof(t_mov));
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	cheapest(stack_a, stack_b, moves);
	free(moves->cheapest);
	free(moves->moves);
	free(moves);
}