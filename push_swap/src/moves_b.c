/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:48:46 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 19:59:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_lst **stack)
{
	t_lst	*prev;
	t_lst	*tmp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	prev = *stack;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	reverse_rotate_a(t_lst **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_lst **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rotate_b(t_lst **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	push_b(t_lst **stack_b, t_lst **stack_a)
{
	t_lst	*node;

	if (!*stack_a)
		return ;
	node = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = node;
	ft_printf("pb\n");
}
