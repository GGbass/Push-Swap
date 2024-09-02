/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:00:03 by gongarci          #+#    #+#             */
/*   Updated: 2024/08/27 22:44:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_lst **stack)
{
	t_lst	*head;
	t_lst	*prev;

	prev = NULL;
	if (!(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	while(head->next->next != NULL)
	{
		prev = head;
		head = head->next;
	}
	if(prev != NULL){
		prev->next = head->next;
		head->next->next = head;
		head->next = NULL;	
	}else{
		*stack = head->next;
		(*stack)->next = head;
		head->next = NULL;	
	}
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

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*node;
	t_lst	*prev;

	if (!*stack_b)
		return ;
	node = *stack_b;
	if ((*stack_b)->next == NULL)
		*stack_b = NULL;
	else
	{
		prev = *stack_b;
		while (prev->next->next != NULL)
			prev = prev->next;
		node = prev->next;
		prev->next = NULL;
	}
	if (*stack_a == NULL)
		*stack_a = node;
	else
	{
		prev = *stack_a;
		while(prev->next != NULL)
			prev = prev->next;
		prev->next = node;
	}
	ft_printf("pa\n");
}

void	push_b(t_lst **stack_b, t_lst **stack_a)
{
	t_lst	*node;
	t_lst	*prev;

	if (!*stack_a)
		return ;
	node = *stack_a;
	if ((*stack_a)->next == NULL)
		*stack_a = NULL;
	else
	{
		prev = *stack_a;
		while(prev->next->next != NULL)
			prev = prev->next;
		node = prev->next;
		prev->next = NULL;
	}
	if (*stack_b == NULL)
		*stack_b = node;
	else
	{
		prev = *stack_b;
		while(prev->next != NULL)
			prev = prev->next;
		prev->next = node;
	}
	ft_printf("pb\n");
}
