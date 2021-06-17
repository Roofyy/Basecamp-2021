/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:41:14 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/10 15:24:19 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void	display(char *display_file)
{
	int		file;
	char	buffer;

	file = open(display_file, O_RDONLY);
	if (file == -1)
	{
		write(2, "Open error!\n", 12);
		return ;
	}
	while (read(file, &buffer, 1) > 0)
	{
		write(1, &buffer, 1);
	}
	if (close(file) == -1)
	{
		write(2, "Close error!\n", 13);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	else
		display(argv[1]);
	return (0);
}
