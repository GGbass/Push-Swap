/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:19:18 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 19:19:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	free_arrays(char **str, int *array)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	if (array)
		free(array);
}

void	free_stacks(t_lst **stack_a, t_lst **stack_b, char *line)
{
	t_lst	*tmp;

	if (line)
		free(line);
	if ((*stack_a))
	{
		while ((*stack_a))
		{
			tmp = (*stack_a);
			*stack_a = (*stack_a)->next;
			free(tmp);
		}
		free(*stack_a);
	}
	while (*stack_b != NULL)
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
	while (string[i] != '\0')
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
