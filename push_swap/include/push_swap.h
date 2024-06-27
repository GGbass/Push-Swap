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


t_lst	*ft_plstnew(int content);
void	ft_plstadd_front(t_lst **lst, t_lst *new);
void	ft_plstadd_back(t_lst **lst, t_lst *new);
t_lst	*ft_plstlast(t_lst *lst);

#endif