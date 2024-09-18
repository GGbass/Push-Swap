/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:31:10 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 15:31:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stacks(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*head;

	if (!(*stack_a) && !(*stack_b))
		return ;
	while (*stack_a)
	{
		head = (*stack_a)->next;
		free(*stack_a);
		*stack_a = head;
	}
	if (!(*stack_b))
		return ;
	while (*stack_b)
	{
		head = (*stack_b)->next;
		free(*stack_b);
		*stack_b = head;
	}
	ft_printf("stacks frees\n");
}
