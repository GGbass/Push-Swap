/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:01:20 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 19:01:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_lst **a)
{
	if (((*a) == get_lowest(*a)) && (get_highest(*a) == (*a)->next))
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else if (((*a) == get_highest(*a)) && (get_lowest(*a) == tail(*a)))
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if ((*a)->next == get_lowest(*a))
	{
		if (get_highest(*a) == *a)
			rotate_a(a);
		else
			swap_a(a);
	}
	else
		reverse_rotate_a(a);
}

void	sort_four_or_five(t_lst **stack_a, t_lst **stack_b)
{
	int	r;
	int	rr;

	while (list_size(*stack_a) != 3 && check_sort(*stack_a) != 1)
	{
		r = count_r(*stack_a, get_lowest(*stack_a)->value);
		rr = list_size(*stack_a) / 2;
		if (list_size(*stack_a) % 2 != 0)
			rr++;
		if (r < rr)
		{
			while ((*stack_a) != get_lowest(*stack_a))
				rotate_a(stack_a);
		}
		else
		{
			while ((*stack_a) != get_lowest(*stack_a))
				reverse_rotate_a(stack_a);
		}
		push_b(stack_b, stack_a);
	}
	if (check_sort(*stack_a) != 1 && list_size(*stack_a) == 3)
		sort_three(stack_a);
	while (*stack_b != NULL)
		push_a(stack_a, stack_b);
}

static int	push_swap(t_lst **stack_a, int len)
{
	int		sort;
	t_lst	*stack_b;

	stack_b = NULL;
	sort = check_sort(*stack_a);
	if (sort == 1)
		return (free_stacks(stack_a, &stack_b), 0);
	else if (sort == 0 && len == 2)
		swap_a(stack_a);
	else if (sort == 0 && len == 3)
		sort_three(stack_a);
	else if (sort == 0 && len >= 4 && len <= 5)
		sort_four_or_five(stack_a, &stack_b);
	else
		sort1(stack_a, &stack_b);
/* 	if (check_sort(*stack_a) == 0)
		ft_printf("why it's not sorted\n");
	else
		ft_printf("sorted\n"); */
	free_stacks(stack_a, &stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	int		*numbers;
	int		len;
	int		i;

	i = 0;
	stack_a = NULL;
	if (argc > 1)
	{
		len = array_value(argv, &numbers);
		if (len == -1)
			return (ft_printf("Error\n"), -1);
		if (len == 1)
			return (0);
		while (i < len)
		{
			add(&stack_a, numbers[i]);
			i++;
		}
		free(numbers);
		push_swap(&stack_a, len);
	}
	return (0);
}
