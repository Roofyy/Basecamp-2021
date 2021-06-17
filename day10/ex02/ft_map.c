/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:01:15 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/07 20:03:08 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*var;

	i = 0;
	var = (int*)malloc(sizeof(int) * length);
	while (i < length)
	{
		var[i] = (*f)(tab[i]);
		i++;
	}
	return (var);
}
