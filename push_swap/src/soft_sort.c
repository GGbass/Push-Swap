/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:17:08 by marvin            #+#    #+#             */
/*   Updated: 2024/09/07 00:53:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_r(t_lst *stack, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	// tmp = tail(stack);
	tmp = stack;
	while (tmp && tmp->value != value)
	{
		/* ft_printf("tmp->value = %d\n", tmp->value); */
		if (tmp->next == NULL)
		{
			tmp = stack;
		}
		else
			tmp = tmp->next;
		counter++;
	}
	return (counter);
}

t_lst	*tail(t_lst *stack)
{
	t_lst	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
