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

static int	search_in_b(t_lst **stack_b, int a_value)
{
	t_lst	*tmp;
	int		i;
	int		size;
	int		flag;

	i = 0;
	flag = 0;
	tmp = *stack_b;
	size = list_size(*stack_b);
	while (flag == 0 || tmp != NULL)
	{
		i = 0;
		tmp = *stack_b;
		a_value--;
		while (i++ < size)
		{
			if (tmp->value == a_value)
				flag = 1;
			tmp = tmp->next;
		}
	}
	return (a_value);
}

static void	new_value_b(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
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
	rrb_or_rb(moves, size, index);
}

static void	max_moves_in_b(t_lst **stack_b, t_moves *moves)
{
	int	index;
	int	size;

	moves->moves->rb = 0;
	moves->moves->rrb = 0;
	size = list_size(*stack_b);
	index = count_r(*stack_b, get_highest(*stack_b)->value);
	rrb_or_rb(moves, size, index);
}

static void	move_to_b(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	t_lst	*tmp;
	int		size;
	int		i;

	size = list_size(*stack_a);
	i = 0;
	tmp = *stack_a;
	while (i++ < size)
	{
		to_top(stack_a, tmp, i - 1, moves);
		if (tmp->value > get_highest(*stack_b)->value
			|| tmp->value < get_lowest(*stack_b)->value)
			max_moves_in_b(stack_b, moves);
		else
			new_value_b(&tmp, stack_b, moves);
		double_moves(moves);
		cost(moves, i);
		tmp = tmp->next;
	}
}

void	sort1(t_lst **stack_a, t_lst **stack_b)
{
	t_moves	*moves;
	int		size;

	size = list_size(*stack_a);
	moves = ft_calloc(1, sizeof(t_moves));
	if (!moves)
		return ;
	moves->cheapest = ft_calloc(1, sizeof(t_mov));
	moves->moves = ft_calloc(1, sizeof(t_mov));
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	while (size > 2 && !check_sort(*stack_a))
	{
		move_to_b(stack_a, stack_b, moves);
		moving_cheapest(stack_a, stack_b, moves);
		size--;
	}
	sort2(stack_a, stack_b, moves);
	free(moves->cheapest);
	free(moves->moves);
	free(moves);
}
