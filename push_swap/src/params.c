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

int	check_sign(char *string)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while(string[i] != '\0')
	{
		if (string[i + 1] == '\0' && sign == 1)
			return (ft_printf("Error sign out of place\n"), 1);
		if (string[i] == '-' || string[i] == '+')
			sign++;
		if (sign > 1)
			return (ft_printf("Error double sign\n"), 1);
		i++; 
	}
	return (0);
}

/* int	check_sign(char *argv)
{
	char	*substr;

	if (ft_strchr(argv, '-'))
		if (!ft_isdigit(*(ft_strchr(argv, '-') + 1)))
		{
			//ft_printf("strchr -  %d\n", ft_isdigit(*(ft_strchr(argv, '-') + 1)));
			return (ft_printf("Error sign out of place\n"), 1);
		}
	if (ft_strchr(argv, '+'))
		if (!ft_isdigit(*(ft_strchr(argv, '+') + 1)))
		{
			//ft_printf("strchr  + %d\n", ft_isdigit(*(ft_strchr(argv, '-') + 1)));
			return (ft_printf("Error sign out of place\n"), 1);
		}
	substr = ft_substr(argv, 1, ft_strlen(argv));
	if (ft_strchr(substr, '-') || (ft_strchr(substr, '+')))
			return (ft_printf("Error double sign\n"), 1);
	free(substr);
	return (0);
}
 */