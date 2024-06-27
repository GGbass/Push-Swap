/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:40:58 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/27 23:43:51 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_plstnew(int content)
{
	t_lst	*new_content;

	new_content = malloc(sizeof(t_lst));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
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


void	ft_plstadd_front(t_lst **lst, t_lst *new)
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

t_lst	*ft_plstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_plstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last_node;

	if (!*lst)
		*lst = new;
	else
	{
		last_node = ft_plstlast(*lst);
		last_node->next = new;
	}
}

/*int	main()
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew(ft_strdup("node1"));
	ft_lstadd_front(&head, node1);
	node2 = ft_lstnew(ft_strdup("node2"));
	ft_lstadd_front(&head, node2);
	node3 = ft_lstnew(ft_strdup("node3"));
	ft_lstadd_front(&head, node3);

	while (head != NULL && head != node1)
	{
		ft_lstadd_back(&head, node3);
		printf("%s\n", head->content);
		head = head->next;

		ft_lstadd_back(&head, node2);
		printf("%s\n", head->content);
		head = head->next;

		ft_lstadd_back(&head, node1);
		printf("%s\n", head->content);
		head = head->next;
	}

	printf("nada\n");
	return (0);
}*/