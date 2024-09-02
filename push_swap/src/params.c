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

static int	ft_isduplicate(int **numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!numbers || !*numbers)
		return (ft_putstr_fd(" Error\n", 2), 1);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*numbers)[i] == (*numbers)[j])
				return (ft_putstr_fd("Error Duplicated\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_sign(char *string)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (string[i] != '\0')
	{
		if (ft_isalpha(string[i]) == 1)
			return (ft_printf("Error character founded\n"), -1);
		if (string[i] == '-' || string[i] == '+')
		{
			sign++;
			if (ft_blank(string[i + 1]) == 1 && sign >= 1)
				return (ft_printf("Error sign out of place\n"), -1);
		}
		if (sign > 1)
			return (ft_printf("Error double sign\n"), -1);
		i++;
	}
	return (0);
}

static int	argv_checker(int argc, char **argv, int **numbers, int *len)
{
	int	i;

	*len = ft_len(argv);
	i = 0;
	if (argc <= 2)
		return (-1);
	*numbers = malloc(sizeof(int) * ft_len(argv));
	//printf("argv len: %d\n",ft_len(argv));
	if (!*numbers)
		return (-1);
	while (argv[i] != (void *)0)
	{
		if (check_sign(argv[i]) == -1)
			return (-1);
		(*numbers)[i] = ft_atol(argv[i]);
		free(argv[i]);
		i++;
	}
	free(argv);
	// printf("elements in array of int :%d\n", ft_len(argv));
	if (ft_isduplicate(numbers, i) == 1)
		return (-1);
	return (0);
}

int	array_value(int argc, char **argv, int **numbers)
{
	int		i;
	char	**aux2;
	char	*aux;
	int		len;

	i = 1;
	aux = ft_strdup("");
	while (argv[i] != NULL)
	{
		if (ft_empty(argv[i]) == 1)
		{
			ft_printf("Error\n");
			free(aux);
			return (-1);
		}
		aux = ft_gnlstrjoin(aux, argv[i], ft_strlen(argv[i]));
		aux = ft_gnlstrjoin(aux, " ", 1);
		i++;
	}
	aux2 = ft_split(aux, ' ');
	free(aux);
	if (argv_checker(argc, aux2, numbers, &len) == -1)
		return ((ft_printf("Error in checker")), -1);
	return (len);
}
