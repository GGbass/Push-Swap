/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:00:03 by gongarci          #+#    #+#             */
/*   Updated: 2024/08/20 15:55:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_lst **stack_a)
{
	t_lst	*head;
	t_lst	*prev;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	head = *stack_a;
	while(head->next->next != NULL)
	{
		prev = head;
		head = head->next;
	}
 /* prev = 3 head = 4 head->next 5 */
	prev->next = head->next;
	head->next->next = head;
	head->next = NULL;
	ft_printf("sa");
}

void	swap_b(t_lst **stack_b)
{
	t_lst	*head;
	t_lst	*prev;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	head = *stack_b;
	while(head->next->next != NULL)
	{
		prev = head;
		head = head->next;
	}
	prev->next = head->next;
	head->next->next = head;
	head->next = NULL;
	ft_printf("sb");
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
	t_lst	*last;
	t_lst	*tmp;
	t_lst	*first;

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
		first = *stack_a;
		tmp = *stack_a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = first;
		last->next = first->next;
		first->next = NULL;
		*stack_a = last;
	}
	printf("ra\n");
}

/* void	reverse_rotate(t_lst **stack_a)
{
	t_lst	*last;
	t_lst	*tmp;
	t_lst	*first;

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
		
	}
} */
