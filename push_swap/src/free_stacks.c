/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:31:10 by marvin            #+#    #+#             */
/*   Updated: 2024/09/20 23:00:37 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stacks(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;

	if ((*stack_a))
	{
		while ((*stack_a))
		{
			/* if ((*stack_a)->next != NULL) */
			tmp = (*stack_a);
			*stack_a = (*stack_a)->next;
			free(tmp);
		}
		//free(*stack_a);
	}
	while (*stack_b)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
}
