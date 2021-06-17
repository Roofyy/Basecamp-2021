/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:30:40 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 20:16:25 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1

void	print_matrix(int **obs_pot, int *sqr, char *eof, int *axis)
{
	int		y;
	int		x;
	int		ye;
	int		xe;

	ye = sqr[1] + sqr[0];
	xe = sqr[2] + sqr[0];
	y = 0;
	while (y < axis[0])
	{
		x = 0;
		while (x < axis[1])
		{
			if (obs_pot[y][x] > 0)
				ft_putchar(eof[1]);
			else if (y >= sqr[1] && y < ye && x >= sqr[2] && x < xe)
				ft_putchar(eof[2]);
			else
				ft_putchar(eof[0]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	int		*axis;
	char	*eof;
	int		fd;
	int		**obs_pot;
	int		*sqr;

	while (argc > 1)
	{
		sqr = (int*)malloc(sizeof(int) * 3);
		axis = (int*)malloc(sizeof(int) * 2);
		argv++;
		fd = open(*argv, O_RDONLY);
		axis[0] = get_y(fd);
		eof = get_eof(fd);
		axis[1] = get_x(fd);
		obs_pot = find_obs(fd, eof[1], axis);
		obs_pot = find_pot(axis, obs_pot);
		sqr = the_ringleader(axis, obs_pot, sqr);
		print_matrix(obs_pot, sqr, eof, axis);
		free(obs_pot);
		free(eof);
		free(sqr);
		free(axis);
		argc--;
	}
}
