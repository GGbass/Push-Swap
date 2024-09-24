/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_dual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:51:16 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 01:51:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

void	swap_s(t_lst **stack_a, t_lst **stack_b)
{
	if (*stack_a != NULL)
		swap(stack_a);
	if (*stack_b != NULL)
		swap(stack_b);
	ft_printf("ss\n");
}

void	rotate_s(t_lst **stack_a, t_lst **stack_b)
{
	if ((*stack_a) != NULL)
		rotate(stack_a);
	if ((*stack_b) != NULL)
		rotate(stack_b);
	ft_printf("rr\n");
}

void	rotate_a(t_lst **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
