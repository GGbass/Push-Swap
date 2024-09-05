/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:10:33 by gongarci          #+#    #+#             */
/*   Updated: 2024/09/05 07:23:40 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* a.- If tail of b lower than value and highest number of stack b is the same as pointer */

/* b.- if the lowest number of b is greater than value and the pointer is the lowest */

/* if value is lower than current value and value greater than tmp */

static int	find_place(int value, t_lst *current, t_lst *b)
{
	t_lst	*tmp;

	if (current->next == NULL)
	{
		tmp = b;
	}
	else
	{
		tmp = current->next;
	}
	// when tail value is  highest  tail b and  tail b is greater than head b

	//  when tail a is  lower than tail b and tail b is greater than head b
	if (get_highest(b)->value < value && get_highest(b)->value == tmp->value)
		return (1);
	else if (get_lowest(b)->value > value && get_lowest(b)->value == current->value)
		return (1);
	else if (value < current->value && value > tmp->value)
		return (1);
	else
		return (0);
	// when tail a is lower than tail b and tail a is lower to the head b
}

static int	count_ar(t_lst *b, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	tmp = tail(b);
	while (tmp && !find_place(value, tmp, b))
	{
		if (tmp->next == NULL)
		{
			tmp = b;
		}
		else
			tmp = tmp->next;
		counter++;
	}
	//ft_printf("value = %d\n", value);
	return (counter);
}

static int	inspector(t_lst **a, t_lst **b)
{
	int		counter2;
	int		counter3;
	int		counter_a;
	int		counter_b;
	int		counter_a_r;
	int		counter_b_r;
	t_lst	*tmp;

	tmp = (*a)->next;
	if((*b) == NULL)
		return (1);
	counter_a = count_r(*a, (*a)->value);
	counter_b = count_ar(*b, (*a)->value);
	counter_a_r = list_size(*a) - counter_a;
	counter_b_r = list_size(*b) - counter_b;

/* 	if (counter_b >= 3 && counter_a >= 3)
		return (1); */
	while(tmp != NULL)
	{
		counter2 = count_ar(*b, tmp->value);
		counter3 = count_r(*a, tmp->value);
		
		if (int_max(counter2, counter3) < int_max(counter_a, counter_b))
		{
			counter_b = counter2;
			counter_a = counter3;
		}
		if (int_max(list_size(*b) - counter2, list_size(*a) - counter3) < int_max(list_size(*a) - counter_a, list_size(*b) - counter_b))
		{
			counter_b_r = list_size(*b) - counter2;
			counter_a_r = list_size(*a) - counter3;
		}
		tmp = tmp->next;
	}
	if (int_max(counter_b, counter_a) < int_max(counter_b_r, counter_a_r))
	{
		while(counter_b > 0 && counter_a > 0)
		{
			reverse_rr(a,b);
			counter_b--;
			counter_a--;
		}
		while (counter_b-- > 0)
		{
			reverse_rotate_b(b);
		}
		while (counter_a-- > 0)
		{
			reverse_rotate_a(a);
		}
	}
	else
	{
		while(counter_b_r > 0 && counter_a_r > 0)
		{
			rotate_s(a,b);
			counter_b_r--;
			counter_a_r--;
		}
		while (counter_b_r-- > 0)
		{
			rotate_b(b);
		}
		while (counter_a_r-- > 0)
		{
			rotate_a(a);
		}
	}
	return (1);
}

void	sort1(t_lst **stack_a, t_lst **stack_b)
{

	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	if(tail(*stack_b)->value < (*stack_b)->value)
		swap_b(stack_b);
	while (list_size((*stack_a)) != 3 && check_sort(*stack_a) != 1)
	{
		inspector(stack_a, stack_b);
		push_b(stack_b, stack_a);
	}
	if (list_size((*stack_a)) == 3)
		sort_three(stack_a);
/* 	while ((*stack_a) != NULL)
	{
		push_b(stack_b, stack_a);
	} */
	sort2(stack_a, stack_b);
}
