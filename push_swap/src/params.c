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
	char	*substr;
	
	if (ft_strchr(argv, '-'))
		//printf("HELLO\t%u\t%d\n", *ft_strchr(argv, '-'), ft_isdigit(*(ft_strchr(argv, '-') + 1)));
		if (!ft_isdigit(*(ft_strchr(argv, '-') + 1)))
			return (printf("err -\n"), 1);
	if (ft_strchr(argv, '+'))
		//printf("HELLO\t%u\t%d\n", *ft_strchr(argv, '-'), ft_isdigit(*(ft_strchr(argv, '-') + 1)));
		if (!ft_isdigit(*(ft_strchr(argv, '+') + 1)))
			return (printf("err +\n"), 1);
	
	substr = ft_substr(argv, 0, ft_strlen(argv));
	printf("SUBSTR\t%s\n", substr);
	if (ft_strchr(substr, '-')  || ft_strchr(substr, '+'))
	{
		free(substr);
		return (1);
	}
	free(substr);
	return (0);
}

static int	ft_isduplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(argv[i])
	{
		printf("\t%s\n", argv[i]);
		if (check_sign(argv[i]) == 1)
			printf("%s\n", argv[i]);
			//return (ft_putstr_fd("Error isdigit d\n", 2), 1);
		if (ft_isdigit(ft_atoi(argv[i])) == 0)
			return (ft_putstr_fd("Error isdigit d\n", 2), 1);
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
