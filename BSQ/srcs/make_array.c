/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:49:16 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/06/16 16:13:13 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**copy_matrix(char *str)
{
	char	**matrix;
	int		i;
	int		x;
	int		y;

	matrix = malloc(sizeof(char *) * g_lines);
	i = 0;
	x = 0;
	while (x < g_lines)
	{
		y = 0;
		matrix[x] = malloc(sizeof(char) * (g_chars + 1));
		while (y < g_chars)
		{
			matrix[x][y] = str[i];
			i++;
			y++;
		}
		matrix[x][y] = '\0';
		i++;
		x++;
	}
	return (matrix);
}

char	**make_array(char *str)
{
	char **matrix;

	while (str[0] != '\n' && str[0] != '\0')
		str++;
	str++;
	matrix = copy_matrix(str);
	return (matrix);
}
