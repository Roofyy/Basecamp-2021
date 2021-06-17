/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:16:10 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/10 18:59:08 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	error(int err, char *fd)
{
	write(2, "cat: ", 5);
	write(2, fd, ft_strlen(fd));
	if (err == ENOENT)
		write(2, ": No such file or directory\n", 28);
	else if (err == EISDIR)
		write(2, ": Is a directory\n", 17);
}

void	input(void)
{
	char input_char;

	while (read(0, &input_char, 1))
		write(1, &input_char, 1);
}

void	display(int argc, char **argv)
{
	int		file;
	int		count;
	int		j;
	char	buffer[4096];

	count = 1;
	while (count < argc)
	{
		file = open(argv[count], O_RDWR);
		if (file < 0 & errno != 13)
		{
			error(errno, argv[count]);
			count++;
			continue;
		}
		if (file < 0 && errno == 13)
			file = open(argv[count], O_RDONLY);
		while ((j = read(file, buffer, 4096)))
		{
			buffer[j] = '\0';
			write(1, buffer, j);
		}
		close(file);
		count++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		input();
	else
		display(argc, argv);
	return (0);
}
