/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:29:09 by gongarci          #+#    #+#             */
/*   Updated: 2024/07/15 20:05:38 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int i)
{
	if (('a' <= i && i <= 'z' ) || ('A' <= i && i <= 'Z'))
	{
		return (1);
	}
	return (0);
}
