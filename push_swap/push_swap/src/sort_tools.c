/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:08:01 by marvin            #+#    #+#             */
/*   Updated: 2024/09/17 21:30:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*second_highest(t_lst *stack)
{
	t_lst	*highest;
	t_lst	*second;
	t_lst	*tmp;

	highest = get_highest(stack);
	tmp = stack;
	second = stack;
	while(tmp->next != NULL)
	{
		if (second->value < tmp->next->value && tmp->next != highest)
			second = tmp->next;
		tmp = tmp->next;
	}
	return (second);
}

int	check_sort(t_lst *stack_a)
{
	t_lst	*head;

	head = stack_a;
	while(head->next != NULL)
	{
		if (head->value < head->next->value)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

t_lst	*get_highest(t_lst *stack)
{
	t_lst	*tmp;
	t_lst	*highest;

	tmp = stack;
	highest = tmp;
	while(tmp->next != NULL)
	{
		if (highest->value < tmp->next->value)
			highest = tmp->next;
		tmp = tmp->next;
	}
	return (highest);
}

t_lst	*get_lowest(t_lst *stack)
{
	t_lst	*tmp;
	t_lst	*lowest;

	tmp = stack;
	lowest = tmp;
	while(tmp->next != NULL)
	{
		if (lowest->value > tmp->next->value)
			lowest = tmp->next;
		tmp = tmp->next;
	}
	return (lowest);
}

void	sort_three(t_lst **stack_a)
{
	if (((*stack_a) == get_lowest(*stack_a)) && (get_highest(*stack_a) == tail(*stack_a)))
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (((*stack_a) == get_highest(*stack_a)) && (get_lowest(*stack_a) == tail(*stack_a)))
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if ((*stack_a)->next == get_lowest(*stack_a))
	{
		if (get_highest(*stack_a) == *stack_a)
			rotate_a(stack_a);
		else
			swap_a(stack_a);
	}
	else
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
}