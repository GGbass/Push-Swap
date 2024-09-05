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

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	int		*numbers;
	int		len;
	int		i = 0;

	len = array_value(argc, argv, &numbers);
	//printf("Len: %d\n", len);
	if (len <= 0)
		return (ft_printf("Error\n"), -1);
	stack_a = NULL;
	stack_b = NULL;
	while (i < len)
	{
		add(&stack_a, numbers[i], i);
		i++;
	}
	print_list(stack_a);
	push_b(&stack_b, &stack_a);
/* 	push_a(&stack_b, &stack_a);
	push_a(&stack_b, &stack_a); */
	ft_printf("after pushing b\n");

	print_list(stack_a);
	ft_printf("<< stack a \n and b >> \n");
	print_list(stack_b);
	free(numbers);
	//push_swap(&stack_a, &stack_b, len);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
