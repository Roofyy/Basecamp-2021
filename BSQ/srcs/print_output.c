/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:58:39 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/06/16 08:43:33 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_output(char **matrix, t_result res)
{
	int		x;
	int		y;

	x = 0;
	while (x < g_lines)
	{
		y = 0;
		while (y < g_chars)
		{
			if (x >= res.x && x < (res.x + res.size) &&
			y >= res.y && y < (res.y + res.size))
				ft_putchar(g_full);
			else
				ft_putchar(matrix[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
