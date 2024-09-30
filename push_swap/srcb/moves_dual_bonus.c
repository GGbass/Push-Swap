/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_dual_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:10:33 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 18:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	reverse_rr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	swap_s(t_lst **stack_a, t_lst **stack_b)
{
	if (*stack_a != NULL)
		swap(stack_a);
	if (*stack_b != NULL)
		swap(stack_b);
}

void	rotate_a(t_lst **stack_a)
{
	rotate(stack_a);
}

void	rotate_s(t_lst **stack_a, t_lst **stack_b)
{
	if ((*stack_a) != NULL)
		rotate(stack_a);
	if ((*stack_b) != NULL)
		rotate(stack_b);
}
