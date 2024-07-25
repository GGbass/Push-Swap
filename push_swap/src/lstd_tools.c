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

t_lst	*ft_lstnew_node(int content)
{
	t_lst	*new_content;

	new_content = malloc(sizeof(t_lst));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	new_content->prev = NULL;
	return (new_content);
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

void add_node_to_end(t_lst **head, int new_content)
{
	t_lst	*new_node;
	t_lst	*last;

	last = *head;
	new_node = malloc(sizeof(t_lst));
	if (!new_node)
		return ;
	new_node->content = new_content;
	new_node->next = NULL; // As it will be the last node
	new_node->prev = NULL; // This will be updated if it's not the first node
	if (*head != NULL)
	{
		//ft_nodelstlast(last);
		/* while (last->next != NULL)
			last = last->next; */
		last->next = new_node;
		new_node->prev = last; // Set the new node's prev pointer to the last node
	}
	*head = new_node;
}
