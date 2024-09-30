/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:11:28 by marvin            #+#    #+#             */
/*   Updated: 2024/09/09 15:04:33 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_read(char *line, t_lst **a, t_lst **b)
{
	if (!line)
		return ;
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_a(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_s(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_a(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_s(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate_a(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate_b(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		reverse_rr(a, b);
}

static void	get_moves(t_lst **stack_a)
{
	t_lst	*stack_b;
	char	*line;

	stack_b = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		check_read(line, stack_a, &stack_b);
		free(line);
	}
	if (line)
		free(line);
	if (check_sort(*stack_a) && stack_b == NULL)
	{
		ft_printf("OK\n");
		free_stacks(stack_a, &stack_b);
	}
	else
	{
		ft_printf("KO\n");
		free_stacks(stack_a, &stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	int		*numbers;
	int		len;
	int		i;

	i = 0;
	stack_a = NULL;
	if (argc > 1)
	{
		len = array_value(argv, &numbers);
		if (len == -1)
			return (ft_printf("Error\n"), -1);
		if (len == 1)
			return (0);
		while (i < len)
		{
			add(&stack_a, numbers[i]);
			i++;
		}
		free(numbers);
		get_moves(&stack_a);
	}
	return (0);
}
