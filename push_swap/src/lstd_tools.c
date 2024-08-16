/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:01:08 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 19:01:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*new_node(int value)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_nodelstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_lst	*ft_nodelstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_nodelstadd_back(t_lst **lst, t_lst *new_node)
{
	t_lst	*last_node;

	if (!*lst)
		*lst = new_node;
	else
	{
		last_node = ft_nodelstlast(*lst);
		last_node->next = new_node;
	}
}

void	add(t_lst **lst, int value)

{
	t_lst *tmp;
	t_lst *node;

	tmp = *lst;
	node = new_node(value);
	if (*lst == NULL)
		*lst = node;
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}

