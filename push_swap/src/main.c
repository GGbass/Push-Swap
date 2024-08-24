/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:01:20 by marvin            #+#    #+#             */
/*   Updated: 2024/06/28 19:01:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_list(t_lst *stack_a)
{
	t_lst *current;

	current = stack_a;
	if (!current)
		return ;
	if (current->next != NULL)
	{
		print_list(current->next);
	}
	printf("print_list %d\n", current->value);
}

static int	argv_checker(int argc, char **argv, int **numbers)
{
	int	i;

	i = 0;
	if (argc <= 2) 
		return (-1);
	*numbers = malloc(sizeof(int) * ft_len(argv));
	if (!*numbers)
		return (-1);
	while (argv[i] != (void *)0)
	{
		if (check_sign(argv[i]) == -1)
			return (-1);
		(*numbers)[i] = ft_atol(argv[i]);
		free(argv[i]);
		i++;
	}
	free(argv);
	printf("elements in array of int :%d\n", ft_len(argv));
	if (ft_isduplicate(numbers, i) == 1)
		return (-1);
	return (0);
}
int	array_value(int argc, char **argv, int **numbers)
{
	int		i;
	char	**aux2;
	char	*aux;

	i = 1;
	aux = ft_strdup("");
	while (argv[i] != NULL)
	{
		if (ft_empty(argv[i]) == 1)
		{
			ft_printf("Error\n");
			return (-1);
		}
		aux = ft_strjoin(aux, argv[i]);
		aux = ft_strjoin(aux, " ");
		i++;
	}
	aux2 = ft_split(aux, ' ');
	if (argv_checker(argc, aux2, numbers) == -1)
		return((ft_printf("Error in checker")), -1);
	return (ft_len(aux2));
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	int		*numbers;
	int		len;
	int		i;

	i = 0;
	len = array_value(argc, argv, &numbers);
	if (len <= 0)
		return (ft_printf("Error\n"), -1);
	stack_a = NULL;
	stack_b = NULL;
	while(i < len)
		add(&stack_a, numbers[i++]);
	print_list(stack_a);
	rotate_a(&stack_a);
	printf("after ra \n\n");
	print_list(stack_a);
	reverse_rotate_a(&stack_a);
	printf("after reverse ra \n\n");
	print_list(stack_a);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
