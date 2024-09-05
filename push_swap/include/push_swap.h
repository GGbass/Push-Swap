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
	int			index;
	struct s_lst	*next;
}			t_lst;

typedef struct s_values
{
	t_lst		*tail;
	t_lst		*mid;
	t_lst		*prev;
}			t_values;

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


/*linked list tools*/
t_lst		*new_node(int value);
void		print_list(t_lst *stack);
void		add(t_lst **lst, int value, int index);
void		free_stacks(t_lst **stack_a, t_lst **stack_b);
int			list_size(t_lst *stack);
/*	check arguments	*/
int			array_value(int argc, char **argv, int **numbers);
/*	movements	*/
void		swap_a(t_lst **stack_a);
void		swap_b(t_lst **stack_b);
void		swap_s(t_lst **stack_a, t_lst **stack_b);
void		push_a(t_lst **stack1, t_lst **stack2);
void		push_b(t_lst **stack1, t_lst **stack2);
void		rotate_a(t_lst **stack_a);
void		rotate_b(t_lst **stack_b);
void		rotate_s(t_lst **stack_a, t_lst **stack_b);
void		reverse_rotate_a(t_lst **stack_a);
void		reverse_rotate_b(t_lst **stack_b);
void		reverse_rr(t_lst **stack_a, t_lst **stack_b);
/*sort tools*/
t_lst		*get_highest(t_lst *stack);
t_lst		*second_highest(t_lst *stack);
t_lst		*get_lowest(t_lst *stack);
t_values	*get_tail(t_lst *stack);
t_lst		*tail(t_lst *stack);
int			check_sort(t_lst *stack_a);
void		sort_three(t_lst **stack_a);
int			count_r(t_lst *stack, int value);
/*algorithsm */
int			push_swap(t_lst **stack_a, t_lst **stack_b, int len);
void		sort_everything(t_lst **stack_a, t_lst **stack_b);
void		sort1(t_lst **stack_a, t_lst **stack_b);
void		sort2(t_lst **stack_a, t_lst **stack_b);
#endif