/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:17:08 by marvin            #+#    #+#             */
/*   Updated: 2024/09/09 15:16:37 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* count_R is a counter of how many rotations an stack needs to find the value sent */

int	count_r(t_lst *stack, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	tmp = stack;
	while (tmp && tmp->value != value)
	{
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
