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
	int				value;
	struct s_lst	*next;
}			t_lst;

enum e_operation
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
t_lst	*new_node(int value);
t_lst	*ft_nodelstlast(t_lst *lst);
void	ft_nodelstadd_front(t_lst **lst, t_lst *new);
void	add_node_to_end(t_lst **head, int value);
void	add(t_lst **lst, int value);
void	ft_nodelstadd_back(t_lst **lst, t_lst *new_node);
/*	check arguments	*/
int		ft_params(char **argv);
int		check_sign(char *argv);
int		ft_isduplicate(int **numbers, int len);
/*	movements	*/
void	swap_a(t_lst **stack_a);
void	swap_b(t_lst **stack_b);
void	push_a(t_lst **stack_a, t_lst **stack_b);
void	push_b(t_lst **stack_b, t_lst **stack_a);
void	rotate_a(t_lst **stack_a);
void	rotate_b(t_lst **stack_b);
void	reverse_rotate_a(t_lst **stack_a);
void	free_stacks(t_lst **stack_a, t_lst **stack_b);
#endif