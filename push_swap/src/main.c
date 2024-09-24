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
		reverse_rotate_a(stack_a);
}

static void	inspector(t_lst **stack_a, t_lst **stack_b)
{
	int	r;
	int	rr;

	r = count_r(*stack_a, get_lowest(*stack_a)->value);
	rr = list_size(*stack_a) / 2;
	if ((*stack_a) == get_lowest(*stack_a))
			push_b(stack_b, stack_a);
	else if (r < rr)
	{
		while (r > 0 && (*stack_a) != get_lowest(*stack_a))
		{
			rotate_a(stack_a);
			r--;
		}
	}
	else
	{
		while (rr > 0 && (*stack_a) != get_lowest(*stack_a))
		{
			reverse_rotate_a(stack_a);
			rr--;
		}
	}
}

void	sort_four_or_five(t_lst **stack_a, t_lst **stack_b)
{
	while (list_size(*stack_a) != 3 && !check_sort(*stack_a))
	{
		inspector(stack_a, stack_b);
		push_b(stack_b, stack_a);
	}
	if (!check_sort(*stack_a) && list_size(*stack_a) == 3)
		sort_three(stack_a);
	while (*stack_b != NULL)
	{
		if (get_lowest(*stack_b)->next != NULL)
			swap_b(stack_b);
		push_a(stack_a, stack_b);
	}
}

int	push_swap(t_lst **stack_a, int len)
{
	int		sort;
	t_lst	*stack_b;

	stack_b = NULL;
	sort = check_sort(*stack_a);
	if (sort == 1)
		return (free_stacks(stack_a, NULL), 0);
	else if (sort == 0 && len == 2)
		swap_a(stack_a);
	else if (sort == 0 && len == 3)
		sort_three(stack_a);
	else if (sort == 0 && len >= 4 && len <= 5)
		sort_four_or_five(stack_a, &stack_b);
	else
		sort1(stack_a, &stack_b);
	if (check_sort(*stack_a) == 0)
		ft_printf("why it's not sorted\n");
	else
		ft_printf("sorted\n");
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
