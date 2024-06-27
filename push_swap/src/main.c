/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:17:26 by marvin            #+#    #+#             */
/*   Updated: 2024/05/26 23:17:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
Ejercicio 1:
Crear una nodea de tres nodos y mostrarla
*/

/*
Ejercicio 2:
Imprimir el numero de nodos que tiene la nodea
*/


int	main(void)
{

	t_lst	*node;
	t_lst	*node2;
	t_lst	*node3;
	int		i;

	i = 0;
	node = (t_lst*)malloc(sizeof(t_lst));
	node = ft_plstnew(3);
	node2 = (t_lst*)malloc(sizeof(t_lst));
	node2 = ft_plstnew(4);
	node3 = (t_lst*)malloc(sizeof(t_lst));
	node3 = ft_plstnew(5);
	node->next = node2;
	node2->next = node3;
	while(node)
	{
		//ft_printf("%d\n", node->content);
		node = node->next;
		i++;
	}
	ft_printf("%d\n", i);
	return (0);
}


/*
Ejercicio 3:
Añade un nodo al principio y al final. Muestralos
y muesttra el numero de nodos totales.

*/
