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

/* stacit int check_highest(t_lst **a, t_lst **b)
{
	if (get_highest(*a) > get_(highest(*b)))
		return (1);
	else
		return (0);
} */


/* static void	dual_rotate(t_lst **a, t_lst **b, int counter_a, int counter_b)
{
	while(counter_b > 0 && counter_a > 0)
	{
		rotate_s(a,b);
		counter_b--;
		counter_a--;
	}
	while (counter_b-- > 0)
	{
		rotate_b(b);
	}
	while (counter_a-- > 0)
	{
		rotate_a(a);
	}

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
static int	find_place(int value, t_lst *current, t_lst *b)
{
	t_lst	*tmp;

	if (current->next == NULL)
		tmp = b;
	else
		tmp = current->next;
	//1.- if highest b is lower than  head a value && hihgest b is the head b
	//2.- else if logest of b  is > head a value && logest is the head of b
	//3.- else if  value of a < tail of b (current) && value of a > head value
	if (get_highest(b)->value < value && get_highest(b)->value == tmp->value)
		return (1);
	else if (get_lowest(b)->value > value && get_lowest(b)->value == current->value)
		return (1);
	else if (value < current->value && value > tmp->value)
		return (1);
	else
		return (0);
} */

/* static int	count_ar(t_lst *b, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	//tmp = tail(b);
	//tmp = (b)->next;
	tmp = b;
	while (tmp && !find_place(value, tmp, b))
	{
		//ft_printf("tmp->value = %d\n", tmp->value);
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
	//tmp = (*a);
	if((*b) == NULL)
		return (1);
	counter_a = count_r((*a), (*a)->value);
	//counter_a = 0;
	counter_b = count_ar((*b), (*a)->value);
	counter_a_r = list_size(*a) - counter_a;
	counter_b_r = list_size(*b) - counter_b;
	//ft_printf("Before while  values \n");
	//ft_printf("counter_a %d\n", counter_a);
	//ft_printf("counter_b %d\n", counter_b);
	//ft_printf("counter a_r %d\n", counter_a_r);
	//ft_printf("counter b_r %d\n", counter_b_r);
 	while(tmp != NULL)
	{
		//print_list(*a);
		//ft_printf("counter a value %d\n", counter_a);
		//ft_printf("counter_b %d\n", counter_b);
		counter2 = count_ar((*b), tmp->value);
		//ft_printf("counter2 %d\n", counter2);
		counter3 = count_r(*a, tmp->value);
		//ft_printf("counter3 %d\n", counter3);
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
		//ft_printf("times %d\n", i);
	}
	if (int_max(counter_b, counter_a) < int_max(counter_b_r, counter_a_r))
		dual_rotate(a,b,counter_a,counter_b);
	else
		dual_rev_rotate(a,b,counter_a_r,counter_b_r);
	return (1);
} */

void	sort2(t_lst **stack_a, t_lst **stack_b)
{

	int	ra_count = 0;
	int	rra_count = 0;

/* 	ft_printf("\n\n");
	print_list(*stack_a);
	ft_printf("\n\n");
	print_list(*stack_b); */
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