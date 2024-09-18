/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:11:28 by marvin            #+#    #+#             */
/*   Updated: 2024/09/09 15:04:33 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_four_or_five(t_lst **stack_a, t_lst **stack_b)
{
	int		rotations;
	int		reverse_rotations;

	while (list_size(*stack_a) != 3 && check_sort(*stack_a) != 1)
	{
		rotations = count_r(*stack_a, get_lowest(*stack_a)->value);
		reverse_rotations = list_size(*stack_a) - 2 ;
		if ((*stack_a) == get_lowest(*stack_a))
		{
			push_b(stack_b, stack_a);
			continue;
		}
		else if (rotations < reverse_rotations)
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
		sort_four_or_five(stack_a, stack_b);
	else
	{
		sort1(stack_a, stack_b);
	}
	if (check_sort(*stack_a) == 0)
	{
		print_list(*stack_a);
		ft_printf("why it's not sorted\n");
	}
	else
	{	
		// print_list(*stack_a);
		ft_printf("sorted\n");
	}
	return (1);
}
