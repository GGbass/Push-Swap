/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:48:46 by marvin            #+#    #+#             */
/*   Updated: 2024/08/25 18:48:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_lst **stack)
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

void	rotate_a(t_lst **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_lst **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_s(t_lst **stack_a, t_lst **stack_b)
{
	if ((*stack_a) != NULL)
		rotate(stack_a);
	if ((*stack_b) != NULL)
		rotate(stack_b);
	ft_printf("rr\n");
}

void	reverse_rotate(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*head;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	head = *stack;
	tmp = head;
	if (tmp->next->next == NULL)
	{
		head->next = NULL;
		tmp->next = head;
		return ;
	}
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = head;
		*stack = (*stack)->next;
		head->next = NULL;
	}
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
void	reverse_rr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
