/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:00:03 by gongarci          #+#    #+#             */
/*   Updated: 2024/09/18 19:12:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_lst **stack)
{
	t_lst	*head;

	if (!(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	*stack = head->next;
	head->next = (*stack)->next;
	(*stack)->next = head;
}

void	swap_a(t_lst **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_lst **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_lst **stack_a, t_lst **stack_b)
{
	if (*stack_a != NULL)
		swap(stack_a);
	if (*stack_b != NULL)
		swap(stack_b);
	ft_printf("ss\n");
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

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*node;

	if (!*stack_b)
		return ;
	node = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = node;
	ft_printf("pa\n");
}
