/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:43:48 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 20:13:41 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 1
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		get_y(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		content;
	int		len_y;
	int		x;

	len_y = 0;
	x = 0;
	while (read(fd, buf, BUF_SIZE) && buf[0] != '\n')
	{
		x++;
	}
	lseek(fd, 0, SEEK_SET);
	x -= 3;
	while (x > 0)
	{
		content = read(fd, buf, BUF_SIZE);
		buf[content] = '\0';
		len_y = len_y * 10 + ft_atoi(buf);
		x--;
	}
	return (len_y);
}
