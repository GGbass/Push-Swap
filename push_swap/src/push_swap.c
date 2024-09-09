/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:11:28 by marvin            #+#    #+#             */
/*   Updated: 2024/09/07 01:16:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_four_or_five(t_lst **stack_a, t_lst **stack_b, int len)
{
	int		rotations;
	int		reverse_rotations;
	(void) len;

	while (list_size(*stack_a) != 3 && check_sort(*stack_a) != 1)
	{
		rotations = count_r(*stack_a, get_lowest(*stack_a)->value);
		reverse_rotations = list_size(*stack_a) - 2 ;
		if ((*stack_a) == get_lowest(*stack_a))
		{
			push_b(stack_b, stack_a);
			continue;
		}
		if (rotations < reverse_rotations)
		{
			while (rotations > 0 && (*stack_a) != get_lowest(*stack_a))
			{
				rotate_a(stack_a);
				rotations--;
			}
		}
		else
		{
			while (reverse_rotations > 0 && (*stack_a) != get_lowest(*stack_a))
			{
				reverse_rotate_a(stack_a);
				reverse_rotations--;
			}
		}
		push_b(stack_b, stack_a);
	}
	if (check_sort(*stack_a) != 1 && list_size(*stack_a) == 3)
		sort_three(stack_a);
	while (*stack_b != NULL)
	{
		if (get_lowest(*stack_b)->next != NULL)
			swap_b(stack_b);
		push_a(stack_a, stack_b);
	}
}

int	push_swap(t_lst **stack_a, t_lst **stack_b, int len)
{
	int	sort;

	sort = check_sort(*stack_a);
	if (sort == 1)
	{
		print_list(*stack_a);
		return (ft_printf("sorted\n"),0);
	}
	if (sort == 0 && len == 2)
	{
		rotate_a(stack_a);
		printf("sorted\n");
		print_list(*stack_a);
		return (0);
	}
	else if (sort == 0 && len == 3)
		sort_three(stack_a);
	else if (sort == 0 && len == 5)
		sort_four_or_five(stack_a, stack_b, len);
	else
	{
		// sort_four_or_five(stack_a, stack_b, len);
		//sort_everything(stack_a, stack_b);
		sort1(stack_a, stack_b);
	}
	if (check_sort(*stack_a) == 0)
	{
		print_list(*stack_a);
		ft_printf("why it's not sorted\n");
	}
	else
	{	
		print_list(*stack_a);
		ft_printf("sorted\n");
	}
	return (1);
}

/*
int	high_range(t_lst *stack, int *on)
{
	int			i;
	int			j;
	int			size;
	t_lst		*tmp;
	t_lst		*highest;
	t_lst		*second;

	i = 0;
	j = 0;
	size = list_size(stack);
	highest = get_highest(stack);
	second = second_highest(stack);
	tmp = highest;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = second;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
		j++;
	}
	if (size == 4 || i < j || *on == 1)
	{
		if (highest->next == NULL)
		{
			*on = 0;
			return (3);
		}
		else if (highest->next->next == NULL)
			return (2);
		else if (i <= (size / 2))
			return (1);
		else
			return (0);
	}
	else
	{
		if (second->next == NULL)
		{
			*on = 1;
			return (3);
		}
		else if (second->next->next == NULL)
			return (2);
		else if (j <= (size / 2))
			return (1);
		else
			return (0);
	}
}

void	sort_everything(t_lst **stack_a, t_lst **stack_b)
{
	int	todo;
	int	on;

	on = 0;
	while (list_size(*stack_a) != 3)
	{

 		todo = high_range(*stack_a, &on);
		if (todo == 3)
		{
			if ((*stack_b) != NULL && (*stack_b)->next->value > (*stack_b)->value)
				swap_b(stack_b);
			push_b(stack_b, stack_a);
		}
		else if(todo == 2)
		{
			if ((*stack_b) != NULL && (*stack_b)->next->value > (*stack_b)->value)
			{
				swap_s(stack_a, stack_b);
				//on = 0;
			}
			else
				swap_a(stack_a);
		}
		else if (todo == 0)
			reverse_rotate_a(stack_a);
		else if (todo == 1)
			rotate_a(stack_a);
		if (check_sort(*stack_a) == 1)
				return ;
	}
	if ((*stack_b) != NULL && (*stack_b)->next->value > (*stack_b)->value)
	{
		swap_b(stack_b);
			// on = 0;
	}
	if (check_sort(*stack_a) != 1)
		sort_three(stack_a);
	if (get_lowest(*stack_b)->next != NULL)
		swap_b(stack_b);
	while (*stack_b != NULL)
	{
		push_a(stack_a, stack_b);
	}
} */