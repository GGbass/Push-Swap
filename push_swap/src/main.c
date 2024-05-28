/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:17:26 by marvin            #+#    #+#             */
/*   Updated: 2024/05/26 23:17:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("argc is %d\n", ft_len(argv));
	while (i < argc)
	{
		printf("argv %s\n", argv[i]);
		i++;
	}
	printf("Hello, World!\n");
	return (0);
}
