/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:14:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/09 17:25:02 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort2(t_lst **stack_a, t_lst **stack_b)
{
	while (stack_b != NULL)
	{
		// max_min_ in a nd b
		if ((*stack_b)->value < (*stack_a)->value)
			// new_order_min(stack_a, stack_b);
		else if ((*stack_b)->value > get_highest(*stack_a)->value)
		{
			// new_order_max(stack_a, stack_b);
			rotate_a(stack_a);
		}
		else
		{
			// new_a_element(stack_a, stack_b);
		}
	}
	// is_max_min?
	// new_order_min?
}


/* 	print_list(*stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if ((*stack_a)->value < (*stack_a)->next->value)
		swap_a(stack_a);
	while ((list_size(*stack_b) != 0))
	{
		inspector2(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	while (get_lowest(*stack_a) != *stack_a)
	{
		rotate_a(stack_a);
	} */


/* 	int	ra_count = 0;
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
	} */



/* static	void	dual_rotate(t_lst **a, t_lst **b, int counter_a, int counter_b)
{
	while(counter_b > 0 && counter_a > 0)
	{
		rotate_s(a,b);
		counter_b--;
		counter_a--;
	}
	while (counter_b-- > 0)
		rotate_b(b);

	while (counter_a-- > 0)
		rotate_a(a);
}

static void	dual_rev_rotate(t_lst **a, t_lst **b, int counter_a_r, int counter_b_r)
{
	while(counter_b_r > 0 && counter_a_r > 0)
	{
		reverse_rr(a,b);
		counter_b_r--;
		counter_a_r--;
	}
	while (counter_b_r-- > 0)
		reverse_rotate_b(b);
	while (counter_a_r-- > 0)
		reverse_rotate_a(a);
}

static int find_place_a(int value, t_lst *current, t_lst *a)
{
	t_lst	*tmp;

	if (current->next == NULL)
		tmp = a;
	else
		tmp = current->next;
	if (get_highest(a)->value < value && get_highest(a)->value == current->value)
		return (1);
	else if (get_lowest(a)->value > value && get_lowest(a)->value == tmp->value)
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

	//tmp = (*b)->next;
	tmp = *b;
	if((*a) == NULL)
		return (1);
	counter_b = count_r(*b, (*b)->value);
	counter_a = count_bar(*a, (*b)->value);
	counter_a_r = list_size(*a) - counter_a;
	counter_b_r = list_size(*b) - counter_b;

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
	}
	if(int_max(counter_b, counter_a) < int_max(counter_b_r, counter_a_r))
	{
		dual_rev_rotate(a,b,counter_a,counter_b);
	}
	else
	{
		dual_rotate(a,b,counter_a_r,counter_b_r);
	}
	return (1);
}
 */


/* 	while ((*stack_a) != NULL)
	{
		push_b(stack_b, stack_a);
	}
	ft_printf("\n\n");
	print_list(*stack_a);
	ft_printf("\n\n");
	print_list(*stack_b);
	//while ((list_size(*stack_b) != 0))
	while((*stack_b))
	{
		inspector(stack_b, stack_a);
		push_a(stack_a, stack_b);
	}
	print_list(*stack_a);
	while (get_lowest(*stack_a) != *stack_a)
	{
		rotate_a(stack_a);
	} */