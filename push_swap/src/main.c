/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:01:20 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 19:01:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_print_list_reverse(t_lst *lst)
{
	t_lst *last = lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	while (last)
	{
		if (last == NULL)
			break;
		ft_printf("reverse : %d\n", last->content);
		last = last->prev;
	}
}

static int	argv_checker(int argc, char **argv)
{
	if (argc <= 2 || ft_params(argv) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	int		i;
	char	**aux2;
	char	*aux;

	i = 1;
	aux = ft_strdup("");
	while (argv[i] != NULL)
	{
		if (ft_empty(argv[i]) == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		aux = ft_strjoin(aux, argv[i]);
		aux = ft_strjoin(aux, " ");
		i++;
	}
	aux2 = ft_split(aux, ' ');
	if (argv_checker(argc, aux2) == 1)
		return(1);
	lst = NULL;
	i = 0;
	while(aux2[i] != NULL)
	{
		add_node_to_end(&lst, ft_atol(aux2[i]));
		ft_printf("content : %d\n", lst->content);
		i++;
	}
	/* ft_printf("Value of i: %d\n", i); */
	ft_print_list_reverse(lst);
	while (lst)
	{
		t_lst *next = lst->next;
		free(lst);
		lst = next;
	}
	return (0);
}
