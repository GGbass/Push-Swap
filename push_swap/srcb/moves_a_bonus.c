/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:12:39 by marvin            #+#    #+#             */
/*   Updated: 2024/09/25 23:12:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
}

void	swap_b(t_lst **stack_b)
{
	swap(stack_b);
}

void	rotate(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*head;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	head = *stack;
	tmp = head;
	if (tmp->next->next == NULL)
	{
		swap(stack);
		return ;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = head;
		*stack = (*stack)->next;
		head->next = NULL;
	}
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
}
