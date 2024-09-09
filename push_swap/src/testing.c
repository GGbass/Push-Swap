/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:14:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/08 21:53:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int find_place_a(int value, t_lst *current, t_lst *b)
{
	t_lst	*tmp;

	if (current->next == NULL)
		tmp = b;
	else
		tmp = current->next;
	// when tail value is  highest  tail b and  tail b is greater than head b

	// when tail a is  lower than tail b and tail b is greater than head b
	if (get_highest(b)->value < value && get_highest(b)->value == current->value)
		return (1);
	else if (get_lowest(b)->value > value && get_lowest(b)->value == tmp->value)
		return (1);
	else if (value < tmp->value && value > current->value)
		return (1);
	else
		return (0);
}

static int	count_bar(t_lst *b, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	//tmp = tail(b);
	tmp = b;
	while (tmp && !find_place_a(value, tmp, b))
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

int	inspector2(t_lst **a, t_lst **b)
{
	int		counter2;
	int		counter3;
	int		counter_a;
	int		counter_b;
	int		counter_a_r;
	int		counter_b_r;
	t_lst	*tmp;
	int	i = 0;

	tmp = (*b)->next;
	if((*a) == NULL)
		return (1);
	counter_b = count_r(*b, (*b)->value);
	counter_a = count_bar(*a, (*b)->value);
	counter_a_r = list_size(*a) - counter_a;
	counter_b_r = list_size(*b) - counter_b;

/* 	if (counter_b >= 3 && counter_a >= 3)
		return (1); */
	while(tmp != NULL)
	{
		counter2 = count_bar(*a, tmp->value);
		counter3 = count_r(*b, tmp->value);
		if (int_max(counter2, counter3) < int_max(counter_a, counter_b))
		{
			counter_a = counter2;
			counter_b = counter3;
		}
		if (int_max(list_size(*b) - counter2, list_size(*a) - counter3) < int_max(list_size(*a) - counter_a, list_size(*b) - counter_b))
		{
			counter_a_r = list_size(*b) - counter2;
			counter_b_r = list_size(*a) - counter3;
		}
		tmp = tmp->next;
		i++;
	}
	if(int_max(counter_b, counter_a) < int_max(counter_b_r, counter_a_r))
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

void	sort2(t_lst **stack_a, t_lst **stack_b)
{
	int	ra_count = 0;
	int	rra_count = 0;

	ft_printf("\n\n");
	print_list(*stack_a);
	ft_printf("\n\n");
	print_list(*stack_b);
	while (list_size(*stack_b) != 0)
	{
		ra_count = count_r((*stack_b), get_highest(*stack_b)->value);
		rra_count = list_size(*stack_b) - ra_count;
		if (ra_count > rra_count)
		{
			while (((*stack_b))->value != get_highest(*stack_b)->value)
			{
				rotate_b(stack_b);
			}
			push_a(stack_a, stack_b);
		}
		else
		{
			while (((*stack_b))->value != get_highest(*stack_b)->value)
			{
				reverse_rotate_b(stack_b);
			}
			push_a(stack_a, stack_b);
		}
	}
/* 	ft_printf("\n\n");
	print_list(*stack_a); */
}




/* 		ra_count = count_r((*stack_b), get_lowest(*stack_b)->value);
		rra_count = list_size(*stack_b) - ra_count;
		if (ra_count > rra_count)
		{	
			while (tail((*stack_b))->value != get_lowest(*stack_b)->value)
			{
				rotate_b(stack_b);
			}
			push_a(stack_a, stack_b);
		}
		else
		{
			while (tail((*stack_b))->value != get_lowest(*stack_b)->value)
			{
				reverse_rotate_b(stack_b);
			}
			push_a(stack_a, stack_b);
		}
	} */


