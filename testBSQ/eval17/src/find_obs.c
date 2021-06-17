/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:28:26 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 14:25:25 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 1
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		*find_tmp_obs(int fd, int *axis, char ob_char)
{
	int		x;
	char	buf[BUF_SIZE + 1];
	int		*tmp_obs;

	tmp_obs = (int*)malloc(sizeof(int) * (axis[1] + 2));
	x = 1;
	while (x <= axis[1])
	{
		read(fd, buf, BUF_SIZE);
		if (buf[0] == ob_char)
			tmp_obs[x - 1] = x;
		x++;
	}
	tmp_obs[x - 1] = 0;
	lseek(fd, 1, SEEK_CUR);
	return (tmp_obs);
}

int		**find_obs(int fd, char ob_char, int *axis)
{
	int		**obs;
	int		*tmp_obs;
	int		y;

	obs = (int**)malloc(sizeof(int*) * (axis[0] + 1));
	lseek(fd, -(axis[1] + 1), SEEK_CUR);
	y = 0;
	while (y < axis[0])
	{
		tmp_obs = find_tmp_obs(fd, axis, ob_char);
		obs[y] = tmp_obs;
		y++;
	}
	return (obs);
}
