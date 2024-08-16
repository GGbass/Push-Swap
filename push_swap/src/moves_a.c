/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:00:03 by gongarci          #+#    #+#             */
/*   Updated: 2024/08/16 18:57:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_lst *lst)
{
	int	tmp;
	t_lst *head;

	if (!(lst) || !(lst->next))
		return ;
	head = lst;
	tmp = lst->value;
	lst->value = lst->next->value;
	lst->next->value = tmp;
	lst = head;
	ft_printf("sa");
}
void	swap_b(t_lst *lst)
{
	int	tmp;
	t_lst *head;

	head = lst;
	tmp = lst->value;
	lst->value = lst->next->value;
	lst->next->value = tmp;
	lst = head;
	ft_printf("sb");
	return ;
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
		while(prev->next->next != NULL)
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
}
/*first element becomes 0 22 335 the last one*/
void	rotate_a(t_lst **stack_a)
{
	t_lst	node;
	t_lst	tmp;

	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	if ((*stack_a)->next->next == NULL)
	{
		tmp = *stack_a;
		tmp->next = NULL;
		(*stack_a)->next = tmp;
	}
	else
	{
		tmp = *stack_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		
	}
	
}