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

/*int	main(void)
{
	t_list	*head;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = ft_lstnew(ft_strdup("node"));
	node1 = ft_lstnew(ft_strdup("node1"));
	node2 = ft_lstnew((ft_strdup("node2")));
	head = node;
	node-> next = node1;
	node1-> next = node2;
	while (head != NULL)
	{
		printf("%s\n", head->content);
		head = head->next;
	}

	return (0);
}*/


void	ft_nodelstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*head;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = ft_lstnew(ft_strdup("node"));
	node1 = ft_lstnew(ft_strdup("node1"));
	node2 = ft_lstnew(ft_strdup("node2"));
	while (head != NULL)
	{
		ft_lstadd_front(&head, node);
		printf("%s\n", head->content);
		ft_lstadd_front(&head, node1);
		printf("%s\n", head->content);
		ft_lstadd_front(&head, node2);
		printf("%s\n", head->content);
	}
	return (0);
}*/

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
	t_lst	*new_node = malloc(sizeof(t_lst));
	t_lst	*last = *head;
	if (!new_node)
		return ;
	new_node->content = new_content;
	new_node->next = NULL; // As it will be the last node
	new_node->prev = NULL; // This will be updated if it's not the first node

	if (*head == NULL)
	{
		*head = new_node; // List was empty, new node is now the head
	}
	else
	{
		//ft_nodelstlast(last);
		/* while (last->next != NULL)
			last = last->next; */
		last->next = new_node;
		new_node->prev = last; // Set the new node's prev pointer to the last node
	}
}
