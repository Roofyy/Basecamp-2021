/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringleader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:06:00 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 20:32:47 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1

int		*the_ringleader(int *axis, int **obs_pot, int *sqr)
{
	int		x;
	int		y;
	int		tmp_sqr[2];
	int		tmp_size;

	y = 0;
	x = 0;
	sqr[0] = 0;
	tmp_sqr[0] = 0;
	tmp_sqr[1] = 0;
	while (y < axis[0])
	{
		y = tmp_sqr[0];
		x = tmp_sqr[1] + (sqr[0] != 0);
		tmp_size = axis[0];
		while (y < axis[0] && obs_pot[y][x] != -1)
		{
			if (x >= axis[1])
			{
				y++;
				x = 0;
			}
			else
				x++;
		}
		if (y >= axis[0])
			return (sqr);
		tmp_sqr[0] = y;
		tmp_sqr[1] = x;
		while (y - tmp_sqr[0] < tmp_size)
		{
			x = tmp_sqr[1];
			while (obs_pot[y][x] < 1 && x != axis[1] && x < tmp_size + tmp_sqr[1])
				x++;
			if (x < y - tmp_sqr[0])
				tmp_size = y - tmp_sqr[0];
			else
				tmp_size = x - tmp_sqr[1];
			y++;
		}
		if (sqr[0] < tmp_size)
		{
			sqr[0] = tmp_size;
			sqr[1] = tmp_sqr[0];
			sqr[2] = tmp_sqr[1];
		}
	}
	return (sqr);
}
