/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:17:38 by marvin            #+#    #+#             */
/*   Updated: 2024/05/26 23:17:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
	struct s_lst	*prev;
}			t_lst;

/*
#enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};
 */

t_lst	*ft_lstnew_node(int content);
void	ft_nodelstadd_front(t_lst **lst, t_lst *new);
void	ft_nodelstadd_back(t_lst **lst, t_lst *new_node);
t_lst	*ft_nodelstlast(t_lst *lst);
int		ft_params(char **argv);
void	add_node_to_end(t_lst **head, int new_content);

#endif