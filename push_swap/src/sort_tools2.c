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

int	count_r(t_lst *stack, int value)
{
	int		counter;
	t_lst	*tmp;

	counter = 0;
	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value == value)
			return (counter);
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}

t_lst	*tail(t_lst *stack)
{
	t_lst	*tmp;
	t_lst	*tail;

	tmp = stack;
	while (tmp)
	{
		tail = tmp;
		tmp = tmp->next;
	}
	return (tail);
}
