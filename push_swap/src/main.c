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

static int	ft_isduplicate(int **numbers, int len)
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

static void	print_list_reverse(t_lst *lst)
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

static int	argv_checker(int argc, char **argv, int **numbers)
{
	int	i;

	i = 0;
	if (argc <= 2) 
		return (1);
	*numbers = malloc(sizeof(int) * ft_len(argv));
	if (!*numbers)
		return (1);
	while (argv[i] != (void *)0)
	{
		if (check_sign(argv[i]) == -1)
			return (-1);
		(*numbers)[i] = ft_atol(argv[i]);
		i++;
	}
	printf("elements in array of int :%d\n", ft_len(argv));
	if (ft_isduplicate(numbers, i) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	int		i;
	int		*numbers;
	char	**aux2;
	char	*aux;
	//t_lst	*tmp;

	i = 1;
	//tmp = lst;
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
	if (argv_checker(argc, aux2, &numbers) == -1)
		return((ft_printf("Error in checker")),-1);
	lst = NULL;
	i = 0;
	while(i < ft_len(aux2))
	{
		add_node_to_end(&lst, numbers[i]);
		ft_printf("content : %d\n", lst->content);
		i++;
	}
	//swap_a(tmp);
	ft_printf("\n");
	print_list_reverse(lst);
	while (lst)
	{
		t_lst *next = lst->next;
		free(lst);
		lst = next;
	}
	while(*aux2 != NULL)
	{
		free(*aux2);
		aux2++;
	}
	return (0);
}
