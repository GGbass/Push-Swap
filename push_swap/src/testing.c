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

void	reverse_or_rotate(t_moves *moves, int size, int index)
{
	if (size % 2 == 0)
	{
		if (index + 1 > size / 2)
			moves->moves->rra = size - index;
		else
			moves->moves->ra = index + 1;
	}
	else
	{
		if (index > size / 2)
			moves->moves->rra = size - index;
		else
			moves->moves->ra = index + 1;
	}
}

void	double_moves(t_moves *moves)
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

/* stacit int check_highest(t_lst **a, t_lst **b)
{
	if (get_highest(*a) > get_(highest(*b)))
		return (1);
	else
		return (0);
} */
