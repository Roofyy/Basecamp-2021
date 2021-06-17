/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:12:45 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/06/16 09:56:51 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*read_stdin_or_arg(int fd)
{
	char	*buffer;
	char	*temp;
	long	buf_size;
	long	index;

	index = 0;
	buf_size = 1024;
	buffer = malloc(sizeof(char) * (buf_size + 1));
	while (read(fd, &(buffer[index]), 1))
	{
		index++;
		if (index == buf_size)
		{
			temp = malloc(sizeof(char) * (buf_size + 1));
			ft_strcpy(temp, buffer);
			free(buffer);
			buf_size = buf_size * 2;
			buffer = malloc(sizeof(char) * (buf_size + 1));
			ft_strcpy(buffer, temp);
			free(temp);
		}
	}
	buffer[index] = '\0';
	return (buffer);
}

char	*read_input(char *filename)
{
	char	*matrix;
	int		fd;

	if (filename[0] != '\0')
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (0);
	}
	else
		fd = 0;
	matrix = read_stdin_or_arg(fd);
	if (matrix[0] == '\0')
	{
		return (0);
	}
	return (matrix);
}
