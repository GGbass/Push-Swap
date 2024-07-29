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

static int	check_sign(char *argv)
{
	if (ft_strchr(argv, '-') || ft_strchr(argv , '+'))
		if (!ft_isdigit(*(ft_strchr(argv, '-') + 1)))
			return (ft_printf("err -\n"), 1);
	if (ft_strchr(argv, '+'))
		if (!ft_isdigit(*(ft_strchr(argv, '+') + 1)))
			return (ft_printf("err +\n"), 1);
	return (0);
}
		//printf("HELLO\t%u\t%d\n", *ft_strchr(argv, '-'), ft_isdigit(*(ft_strchr(argv, '-') + 1)));
		//printf("HELLO\t%u\t%d\n", *ft_strchr(argv, '-'), ft_isdigit(*(ft_strchr(argv, '-') + 1)));

static int	ft_isduplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(argv[i])
	{
		//ft_printf("%s\n", argv[i]);
		if (check_sign(argv[i]) == 1)
			return (ft_putstr_fd("Error isdigit d\n", 2), 1);
		if (!ft_isdigit(ft_atol(argv[i]) + 48))
		{
			ft_printf("\t%d\n", ft_atoi(argv[i]));
			return (ft_putstr_fd("Error isdigit \n", 2), 1);
		}
		j = i + 1;
		while(argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (ft_putstr_fd("Error atoi D\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_inrange(long int number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (ft_putstr_fd("Error out of range \n", 2), 1);
	return (0);
}

int	ft_params(char **argv)
{
	int	i;

	i = 0;
	while(argv[i] != NULL)
	{
		if (ft_inrange(ft_atol(argv[i])) == 1 || ft_isduplicate(argv) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
