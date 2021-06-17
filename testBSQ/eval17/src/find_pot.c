/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhujanen <mhujanen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:28:13 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 17:19:09 by mhujanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1

int		**find_pot(int *axis, int **obs_pot)
{
	int		x;
	int		y;
	int		tmp_y;

	y = 0;
	while (y < axis[0] - 1)
	{
		x = 0;
		while (x < axis[1])
		{
			if (obs_pot[y][x] < 1)
			{
				x++;
				continue ;
			}
			if (obs_pot[y + 1][x + 1] == 0)
			{
				if (x < axis[1] - 1)
				{
					obs_pot[y + 1][x + 1] = -1;
					while (tmp_y-- > 0)
					{
						if (obs_pot[tmp_y][axis[1]] == 1)
						{
							if (obs_pot[tmp_y][x + 1] == 0)
								obs_pot[tmp_y][x + 1] = -1;
						}
					}
				}
				obs_pot[y + 1][axis[1]] = 1;
				tmp_y = y;
			}
			if (obs_pot[0][x + 1] == 0 && y != 0 && x < axis[1] - 1)
				obs_pot[0][x + 1] = -1;
			if (obs_pot[y + 1][0] == 0 && x != 0)
				obs_pot[y + 1][0] = -1;
			if (obs_pot[y][x + 1] == 0 && x < axis[1] - 1)
				obs_pot[y][x + 1] = -1;
			if (obs_pot[y + 1][x] == 0)
				obs_pot[y + 1][x] = -1;
			x++;
		}
		y++;
	}
	return (obs_pot);
}
