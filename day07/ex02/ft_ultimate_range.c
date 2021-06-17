/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:38:38 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/03 18:13:24 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*var;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	var = (int*)malloc((max - min) * sizeof(int));
	if (var == NULL)
	{
		return (0);
	}
	while (min < max)
	{
		var[i] = min++;
		i++;
	}
	*range = var;
	return (i);
}
