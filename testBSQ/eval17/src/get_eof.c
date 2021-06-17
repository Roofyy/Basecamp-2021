/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:44:45 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 20:13:46 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 1
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_eof(int fd)
{
	int		x;
	char	buf[BUF_SIZE + 1];
	char	*eof;

	eof = (char *)malloc(sizeof(char) * 4);
	x = 0;
	while (x < 3)
	{
		read(fd, buf, BUF_SIZE);
		eof[x] = buf[0];
		x++;
	}
	eof[x] = '\0';
	return (eof);
}
