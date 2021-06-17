/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:42:36 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 11:55:56 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 1
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		get_x(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		x;

	x = 0;
	lseek(fd, 1, SEEK_CUR);
	while (read(fd, buf, BUF_SIZE))
	{
		if (buf[0] == '\n')
			break ;
		x++;
	}
	return (x);
}
