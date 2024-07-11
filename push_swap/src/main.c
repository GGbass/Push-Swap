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
		ft_printf("reverse : %d\n", last->content);
		last = last->prev;
		if (last->prev == NULL)
			break;
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
	//t_lst	*temp;
	int		i;

	i = 1;
	lst = NULL;
	if (argv_checker(argc, argv) == 1)
		return(1);
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (ft_putstr_fd("Error allocating memory\n", 2), 0);
	lst->content = ft_atoi(argv[i]);
	while(++i <= argc - 1)
	{
		ft_printf("content : %d\n", lst->content);
		add_node_to_end(&lst, ft_atoi(argv[i]));
		lst = lst->next;
	}
	ft_printf("here 1 \n");
	ft_printf("Value of i: %d\n", i);
	//temp = lst;
	/*while (temp->next != NULL)
	 {
		temp->next->prev = temp->prev;
		ft_printf("prev : %d\n", temp->prev->content);
		temp = temp->next;
	} */
	ft_print_list_reverse(lst);
	while (lst)
	{
		t_lst *next = lst->next;
		free(lst);
		lst = next;
	}
	return (0);
}
