/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:36:44 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/03 17:22:06 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *range;
	int *var;

	if (min >= max)
	{
		return (NULL);
	}
	range = malloc((max - min) * sizeof(int));
	if (!range)
	{
		return (NULL);
	}
	var = range;
	while (min < max)
	{
		*var++ = min++;
	}
	return (range);
}
