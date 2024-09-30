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

#include "../include/checker.h"

static int	check_read(char *line, t_lst **a, t_lst **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (swap_a(a), 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (swap_b(b), 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (swap_s(a, b), 1);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (push_a(a, b), 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (push_b(b, a), 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (rotate_a(a), 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rotate_b(b), 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		return (rotate_s(a, b), 1);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		return (reverse_rotate_a(a), 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (reverse_rotate_b(b), 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (reverse_rr(a, b), 1);
	else
		return (-1);
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
			break ;
		if (!(check_read(line, stack_a, &stack_b)))
			return (free_stacks(stack_a, &stack_b, line));
		free(line);
	}
	if (check_sort(*stack_a) && stack_b == NULL)
	{
		ft_printf("OK\n");
		free_stacks(stack_a, &stack_b, NULL);
	}
	else
	{
		ft_printf("KO\n");
		free_stacks(stack_a, &stack_b, NULL);
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
