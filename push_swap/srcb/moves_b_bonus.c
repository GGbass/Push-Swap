/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:47:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 17:47:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
}

void	reverse_rotate_b(t_lst **stack_b)
{
	reverse_rotate(stack_b);
}

void	rotate_b(t_lst **stack_b)
{
	rotate(stack_b);
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
}
