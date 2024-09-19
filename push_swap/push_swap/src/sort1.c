/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:10:33 by gongarci          #+#    #+#             */
/*   Updated: 2024/09/09 17:05:16 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	dual_rotate(t_lst **a, t_lst **b, int counter_a, int counter_b)
{
	while(counter_b > 0 && counter_a > 0)
	{
		rotate_s(a,b);
		counter_b--;
		counter_a--;
	}
	while (counter_b-- > 0)
	{
		//  if (counter_b > 3)
		// 	return ;
		rotate_b(b);
	}
	while (counter_a-- > 0)
	{
		// if (counter_a > 3)
		// 	return ; 
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

static int	find_place(int value, t_lst *tail_b, t_lst *b)
{
	t_lst	*tmp;

	 if (tail_b->next == NULL)
		tmp = b;
	else
		tmp = tail_b->next;
	// Si el valor más alto en b es menor que value y es igual al valor de tmp, imprime "a" y devuelve 1.
	// Si el valor más bajo en b es mayor que value y es igual al valor de tail_b, imprime "b" y devuelve 1.
	// Si value es menor que el valor de tail_b y mayor que el valor de tmp, imprime
	//1.- if highest b is lower than  head a value && hihgest b is the head b
	//2.- else if logest of b  is > head a value && logest is the head of b
	//3.- else if  value of a < tail of b (current) && value of a > head value
	if (get_highest(b)->value < value && get_highest(b)->value == tmp->value)
	{
		ft_printf("a\n");
		return (1);
	}
	else if (get_lowest(b)->value > value && get_lowest(b)->value == tail_b->value)
	{
		ft_printf("b\n");
		return (1);
	}
	else if (value < tail_b->value && value > tmp->value)
	{
		ft_printf("c\n");
		return (1);
	}	
	else
		return (0);
}

static int	count_ar(t_lst *b, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	tmp = tail(b);
	// tmp = b;
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
	// target node it has to be the biggest the smalles biggest
	// that means what is on head b  will target to the biggest on A
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
	//tmp = get_highest(*a);
	//tmp = tail(*a);
	if((*b) == NULL)
		return (1);
	counter_a = count_r((*a), (*a)->value);
	//counter_a = 0;
	counter_b = count_ar((*b), (*a)->value);
	print_list(*b);
	ft_printf("counter_b = %d\n", counter_b);
	ft_printf("counter_a = %d\n", (*a)->value);
	counter_a_r = list_size(*a) - counter_a;
	counter_b_r = list_size(*b) - counter_b;
 	while(tmp != NULL)
	{
		counter2 = count_ar((*b), tmp->value);
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
		dual_rotate(a,b,counter_a,counter_b);
	else
		dual_rev_rotate(a,b,counter_a_r,counter_b_r);
	return (1);
}

void	sort1(t_lst **stack_a, t_lst **stack_b)
{
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	if ((*stack_b)->value > (*stack_b)->next->value)
		swap_b(stack_b);
	while (list_size((*stack_a)) != 3 && check_sort(*stack_a) != 1)
	{
		inspector(stack_a, stack_b);
		// ft_printf("\npushing %d\n", (*stack_a)->value);
		push_b(stack_b, stack_a);
	}
	if (list_size((*stack_a)) == 3)
		sort_three(stack_a);
	/* while ((*stack_a) != NULL)
	{
		push_b(stack_b, stack_a);
	} */
	//sort2(stack_a, stack_b, moves);
}
