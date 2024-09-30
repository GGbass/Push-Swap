/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:30:22 by marvin            #+#    #+#             */
/*   Updated: 2024/09/25 19:30:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
}				t_lst;


void	print_list(t_lst *stack_a);
void	add(t_lst **lst, int value);
int		list_size(t_lst *stack);
int		words(char *string);
void	free_stacks(t_lst **stack_a, t_lst **stack_b);
void	free_arrays(char **str, int *array);
int		array_value(char **argv, int **numbers);
int		check_sort(t_lst *stack_a);
/* movements */
void	push_a(t_lst **stack_a, t_lst **stack_b);
void	push_b(t_lst **stack_b, t_lst **stack_a);
void	swap(t_lst **stack);
void	swap_a(t_lst **stack_a);
void	swap_b(t_lst **stack_b);
void	swap_s(t_lst **stack_a, t_lst **stack_b);
void	reverse_rotate(t_lst **stack);
void	reverse_rotate_a(t_lst **stack_a);
void	reverse_rotate_b(t_lst **stack_b);
void	reverse_rr(t_lst **stack_a, t_lst **stack_b);
void	rotate(t_lst **stack);
void	rotate_a(t_lst **stack_a);
void	rotate_b(t_lst **stack_b);
void	rotate_s(t_lst **stack_a, t_lst **stack_b);

#endif