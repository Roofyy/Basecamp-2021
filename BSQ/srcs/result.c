/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:01:54 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/16 10:15:08 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				min(int first, int second, int third)
{
	if (first <= second && first <= third)
	{
		return (first);
	}
	else if (second <= first && second <= third)
	{
		return (second);
	}
	else
	{
		return (third);
	}
}

t_result		update_result(int current, t_result res, int i, int j)
{
	if (current > res.size)
	{
		res.size = current;
		res.x = i - res.size + 1;
		res.y = j - res.size + 1;
	}
	return (res);
}

t_result		find_result(char **array, int height, int length, int **c)
{
	int			i;
	int			j;
	t_result	res;

	i = 0;
	res.size = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			if (array[i][j] == g_obstacle)
				c[i][j] = 0;
			else if (i == 0 || j == 0)
				c[i][j] = 1;
			else
				c[i][j] = 1 + min(c[i][j - 1], c[i - 1][j], c[i - 1][j - 1]);
			res = update_result(c[i][j], res, i, j);
			j++;
		}
		i++;
	}
	return (res);
}
