/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:31:10 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 01:33:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ar_str_free(char **array)
{
	int	i;

	i = 0;
	while(array[i] != NULL)
		free(array[i++]);
	free(array);
}

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
		free(*stack_a);
	}
	while (*stack_b)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
}

int	words(char *string)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while(string[i] != '\0')
	{
		if (ft_blank(string[i]) == 1)
		{
			while ((ft_blank(string[i]) == 1))
				i++;
			words++;
		}
		i++;
	}
	return (words);
}
