/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:04:17 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 02:04:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cost(t_moves *moves, int i)
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

void	moving_cheapest(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
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
void	to_top(t_lst **stack_a, t_lst *tmp, int i, t_moves *moves)
{
	int		size;

	moves->moves->pb = 1;
	moves->moves->ra = 0;
	moves->moves->rra = 0;
	if ((*stack_a)->value == tmp->value)
		return ;
	size = list_size(*stack_a);
	rra_or_ra(moves, size, i);
}
/* b to a .c tool */

void	do_moves(t_lst **stack_a, t_lst **stack_b, t_moves *moves, int push)
{
	while (moves->moves->rra-- != 0)
		reverse_rotate_a(stack_a);
	while (moves->moves->ra-- != 0)
		rotate_a(stack_a);
	if (push == 1)
		push_a(stack_a, stack_b);
}