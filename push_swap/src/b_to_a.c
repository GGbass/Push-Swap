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

static	void	do_moves(t_lst **stack_a, t_lst **stack_b, t_moves *moves, int push)
{
	while (moves->moves->rra-- != 0)
		reverse_rotate_a(stack_a);
	while (moves->moves->ra-- != 0)
		rotate_a(stack_a);
	if (push == 1)
		push_a(stack_a, stack_b);
}

static int	search_in_a(t_lst **stack_a, int b_value)
{
	t_lst 	*tmp;
	int		i;
	int		size;
	int		flag;

	i = 0;
	flag = 0;
	tmp = *stack_a;
	size = list_size(*stack_a);
	while(flag == 0 || tmp != NULL)
	{
		i = 0;
		tmp = *stack_a;
		b_value++;
		while(i++ < size)
		{
			if (tmp->value == b_value)
				flag = 1;
			tmp = tmp->next;
		}
	}
	return (b_value);
}

static void	new_value_a(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	int	index;
	int	size;
	int	search;

	moves->moves->ra = 0;
	moves->moves->rra = 0;
	size = list_size(*stack_a);
	search = search_in_a(stack_a, (*stack_b)->value);
	index = count_r(*stack_a, search);
	if ((*stack_a)->value == search)
		return ;
	else
	{
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				moves->moves->rrb = size - index;
			else
				moves->moves->rb = index;
		}
		else
		{
			if (index > size / 2)
				moves->moves->rrb = size - index;
			else
				moves->moves->rb = index;
		}
	}
	// add reverse or rotate function here
	// apply moves and check for push
	do_moves(stack_a, stack_b, moves, 1);
}

static void	new_order_max(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
// if((*stack_b)->value > get_highest(*stack_a)->value)
	int	size;
	int	index;

	size = list_size(*stack_a);
	index = count_r(*stack_a, get_highest(*stack_a)->value);
	if (tail(*stack_a)->value != get_highest(*stack_a)->value)
	{
		if (size % 2 == 0)
		{
			if (index + 1 >  size / 2)
				moves->moves->rra = size - index;
			else
				moves->moves->ra = index + 1;
		}
		else
		{
			if (index > size / 2)
				moves->moves->rra = size - index;
			else
				moves->moves->ra = index + 1;
		}
	}
	// add reverse or rotate function here
	//apply moves and check for push
	do_moves(stack_a, stack_b, moves, 1);
}

static void	new_order_min(t_lst **stack_a, t_lst **stack_b, t_moves *moves, int flag)
{
//if ((*stack_b)->value < get_lowest((*stack_a))->value)
	int	size;
	int	index;

	size = list_size(*stack_a);
	index = count_r(*stack_a, get_lowest(*stack_a)->value);
	moves->moves->ra = 0;
	moves->moves->rra = 0;
	if ((*stack_a)->value  != get_lowest(*stack_a)->value)
	{
		if (size % 2 == 0)
		{
			if (index + 1 >  size / 2)
				moves->moves->rra = size - index;
			else
				moves->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				moves->moves->rra = size - index;
			else
				moves->moves->ra = index;
		}
	}
	// add reverse or rotate function here
	//apply moves and check for push
	do_moves(stack_a, stack_b, moves, flag);
}

void	sort2(t_lst **stack_a, t_lst **stack_b, t_moves *moves)
{
	while (stack_b != NULL)
	{
		if ((*stack_b)->value < get_lowest((*stack_a))->value)
			new_order_min(stack_a, stack_b, moves, 1);
		else if((*stack_b)->value > get_highest(*stack_a)->value)
		{
			new_order_max(stack_a, stack_b, moves);
			rotate_a(stack_a);
		}
		else
		{
			new_value_a(stack_a, stack_b, moves);
		}
	}
	// is_max_min?
	// new_order_min?
	new_order_min(stack_a, stack_b, moves, 0);
}

////////////////////////////////////////


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