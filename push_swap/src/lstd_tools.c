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

/* void	print_list(t_lst *stack_a)
{
	t_lst	*current;

	current = stack_a;
	if (!current)
		return ;
	while(current != NULL)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	return ;
} */

void	print_list(t_lst *stack)
{
	t_lst	*current;

	current = stack;
	if (!current)
		return ;
	if (current->next != NULL)
	{
		print_list(current->next);
	}
	ft_printf("print_list %d\n", current->value);
	return ;
}

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

void	add(t_lst **lst, int value, int index)
{
	t_lst	*tmp;
	t_lst	*node;

	tmp = *lst;
	node = new_node(value);
	// ft_printf("add value = %d\n", value);
	// ft_printf("add index = %d\n\n", index);
	node->index = index;
	if (*lst == NULL)
		*lst = node;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}

int	list_size(t_lst *stack)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = stack;
	while(tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_values	*get_tail(t_lst *stack)
{
	t_values	*values;
	t_lst		*tmp;

	/*delete this malloc and must be used  outside */
	values = malloc(sizeof(t_values));
	if (!values)
		return (NULL);
	tmp = stack;
	while(tmp->next->next != NULL)
	{
		values->prev = tmp;
		values->mid = tmp->next;
		values->tail = tmp->next->next;
		tmp = tmp->next;
	}
	return (values);
}
