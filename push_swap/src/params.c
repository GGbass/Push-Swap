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

int	ft_isduplicate(int **numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ( !numbers || !*numbers)
		return (ft_putstr_fd("Error\n", 2), 1);
	while(i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if ((*numbers)[i] == (*numbers)[j])
				return (ft_putstr_fd("Error Duplicated\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sign(char *string)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while(string[i] != '\0')
	{
		if (ft_isalpha(string[i]) == 1)
			return(ft_printf("Error character founded\n"), -1);
		if (string[i] == '-' || string[i] == '+')
		{
			sign++;
			if (ft_blank(string[i+1]) == 1 && sign >= 1)
				return (ft_printf("Error sign out of place\n"), -1);
		}
		if (sign > 1)
			return (ft_printf("Error double sign\n"), -1);
		i++;
	}
	return (0);
}
