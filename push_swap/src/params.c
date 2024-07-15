/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:01:51 by marvin            #+#    #+#             */
/*   Updated: 2024/07/03 21:01:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isduplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while(argv[i])
	{
		if (ft_isdigit(ft_atoi(argv[i])) == 0)
			return (ft_putstr_fd("Error isdigit D\n", 2), 1);
		if (argv[i][0])
		j = i + 1;
		while(argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (ft_putstr_fd("Error atoi D\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_inrange(int number)
{
	if (number <= INT_MIN || number >= INT_MAX)
		return (ft_putstr_fd("Error out of range \n", 2), 1);
	return (0);
}

int	ft_params(char **argv)
{
	int	i;

	i = 1;
	while(argv[i])
	{
		if (ft_inrange(ft_atoi(argv[i])) == 1 || ft_isduplicate(argv) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
