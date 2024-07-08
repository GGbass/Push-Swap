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

static void ft_print_list_reverse(t_lst *lst)
{
	t_lst *last = lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	// Step 2: Iterate Backwards and Print Each Node's Content
	while (last != NULL) 
	{
		ft_printf("reverse\n");
		ft_printf("%d\n", last->content); // Assuming 'content' is an int
		last = last->prev;
	}
}

static int	argv_checker(int argc)
{
	if (argc <= 2 && argc != 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*temp;
	int		i;

	if (argv_checker(argc) != 0)
		return(0);
	lst = (t_lst *)malloc(sizeof(t_lst) * argc);
	if (!lst)
		return (ft_putstr_fd("Error\n", 2), 0);
	while(++i < argc)
	{
		add_node_to_end(&lst, ft_atoi(argv[i]));
		ft_printf("foward\n", lst->content);
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
	ft_printf("Value of i: %d\n", i);
	temp = lst;
	while (temp->next != NULL)
	{
		temp->next->prev = temp;
		temp = temp->next;
	}
	ft_print_list_reverse(lst);
	while (lst)
	{
		t_lst *next = lst->next;
		free(lst);
		lst = next;
	}
	return (0);
}
