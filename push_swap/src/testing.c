/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:14:50 by marvin            #+#    #+#             */
/*   Updated: 2024/08/29 11:14:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_lst	*tail(t_lst *stack)
{
	t_lst	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

static int count_r(t_lst *stack, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	// ft_printf("index = %d\n", value);
	tmp = tail(stack);
	while (tmp && tmp->value != value)
	{
		// printf("count ar \n");
		if (tmp->next == NULL)
		{
			/* ft_printf("tmp->value = %d\n", tmp->value);
			ft_printf("stack->value = %d\n", stack->value); */
			tmp = stack;
		}
		else
			tmp = tmp->next;
		counter++;
	}
	return (counter);
}
static int find_place_a(int value, t_lst *current, t_lst *b)
{
	t_lst	*tmp;
	if (current->next == NULL)
		tmp = b;
	else
		tmp = current->next;
	// when tail value is  highest  tail b and  tail b is greater than head b

	//  when tail a is  lower than tail b and tail b is greater than head b
	if (get_highest(b)->value < value && get_highest(b)->value == current->value)
		return (1);
	else if (get_lowest(b)->value > value && get_lowest(b)->value == tmp->value)
		return (1);
	else if (value < tmp->value && value > current->value)
		return (1);
	else
		return (0);
}

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

static int	count_bar(t_lst *b, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	tmp = tail(b);
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

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int	inspector(t_lst **a, t_lst **b)
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
		
		if (max(counter2, counter3) < max(counter_a, counter_b))
		{
			counter_b = counter2;
			counter_a = counter3;
		}
		if (max(list_size(*b) - counter2, list_size(*a) - counter3) < max(list_size(*a) - counter_a, list_size(*b) - counter_b))
		{
			counter_b_r = list_size(*b) - counter2;
			counter_a_r = list_size(*a) - counter3;
		}
		tmp = tmp->next;
	}
	if(max(counter_b, counter_a) < max(counter_b_r, counter_a_r))
	{
		while(counter_b > 0 && counter_a > 0)
		{
			reverse_rr(a,b);
			counter_b--;
			counter_a--;
		}
		/* if (counter_b > 5 || counter_a > 5)
			return (1); */
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
		/* if (counter_b_r > 5 || counter_a_r > 5)
			return (1); */
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

int	inspector2(t_lst **a, t_lst **b)
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
	counter_b = count_r(*b, (*b)->value);
	counter_a = count_bar(*a, (*b)->value);
	counter_a_r = list_size(*a) - counter_a;
	counter_b_r = list_size(*b) - counter_b;

/* 	if (counter_b >= 3 && counter_a >= 3)
		return (1); */
	while(tmp != NULL)
	{
		counter2 = count_bar(*b, tmp->value);
		counter3 = count_r(*a, tmp->value);
		
		if (max(counter2, counter3) < max(counter_a, counter_b))
		{
			counter_a = counter2;
			counter_b = counter3;
		}
		if (max(list_size(*b) - counter2, list_size(*a) - counter3) < max(list_size(*a) - counter_a, list_size(*b) - counter_b))
		{
			counter_a_r = list_size(*b) - counter2;
			counter_b_r = list_size(*a) - counter3;
		}
		tmp = tmp->next;
	}
	if(max(counter_b, counter_a) < max(counter_b_r, counter_a_r))
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
void	k_sort1(t_lst **stack_a, t_lst **stack_b)
{

	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	if(tail(*stack_b)->value > (*stack_b)->value)
		swap_b(stack_b);
	while (list_size((*stack_a)) != 3 && check_sort(*stack_a) != 1)
	{
		/* print_list(*stack_a);
		ft_printf("\n\n");
		ft_printf("<<< a \n\n >>>  b \n\n");
		print_list(*stack_b); */
	/* 	print_list(*stack_a);
		ft_printf("stack a\n\n"); */
		inspector(stack_a, stack_b);
		push_b(stack_b, stack_a);
	}
	if (list_size((*stack_a)) == 3)
		sort_three(stack_a);
	while ((*stack_a) != NULL)
		push_b(stack_b, stack_a);
	k_sort2(stack_a, stack_b);
}

void	k_sort2(t_lst **stack_a, t_lst **stack_b)
{
	int	ra_count;
	int	rra_count;
	// ft_printf("k_sort2\n");
	/* print_list(*stack_b); */
	while (list_size(*stack_b) != 0)
	{
		/* print_list(*stack_b);
		ft_printf("stack b<<<<\n\n>>>>\n");
		print_list(*stack_a);
		ft_printf("\n\n"); */
		// inspector2(stack_a, stack_b);
		// push_a(stack_a, stack_b);
		// ft_printf("second while \n");
		ra_count = count_r((*stack_b), get_lowest(*stack_b)->value);
		rra_count = list_size(*stack_b) - ra_count;
		if (ra_count > rra_count)
		{	
			while ((tail(*stack_b))->value != get_lowest(*stack_b)->value)
			{
				rotate_a(stack_b);
			}
			push_a(stack_a, stack_b);

		}
		else
		{
			while ((tail(*stack_b))->value != get_lowest(*stack_b)->value)
			{
				reverse_rotate_a(stack_b);
			}
			push_a(stack_a, stack_b);

		}
		/* ft_printf("end stack_a \n");
		print_list(*stack_a);
		ft_printf("end stack_a \n"); */
	}
}


/* 
	ksort 2
		rb_count = count_r((*stack_b), get_lowest(*stack_b)->value);
		// ft_printf("rb_count = %d\n", rb_count);
		rrb_count = list_size(*stack_b) - rb_count;
		// ft_printf("rrb_count = %d\n", rrb_count);
		//print_list(*stack_b);
		if (rb_count > rrb_count)
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
			push_a(stack_a, stack_b); */