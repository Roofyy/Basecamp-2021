/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:57:04 by osergeev          #+#    #+#             */
/*   Updated: 2021/05/31 16:43:14 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar(char c);

void	print_door(int door, int handle, int size);

void	print_stars(int symbols, int door, int size, int handle);

void	print_floor(int lines, int symbols, int spaces, int door);

int		calculate_floor_diff(int size);

void	sastantua(int size)
{
	int lines;
	int symbols;
	int index;
	int ultimate_symb;
	int spaces;

	index = size;
	lines = 0;
	while (index > 0)
	{
		lines = lines + index + 2;
		index--;
	}
	ultimate_symb = 3 + ((lines - 1) * 2) + calculate_floor_diff(size);
	lines = 0;
	index = 1;
	while (index <= size)
	{
		lines = lines + index + 2;
		symbols = 3 + ((lines - 1) * 2) + calculate_floor_diff(index);
		spaces = (ultimate_symb - symbols) / 2;
		print_floor(index + 2, symbols, spaces, index == size);
		index++;
	}
}

int		calculate_floor_diff(int size)
{
	int floor_diff;

	floor_diff = 0;
	while (size > 1)
	{
		floor_diff = floor_diff + (size / 2 * 2) + 2;
		size--;
	}
	return (floor_diff);
}

void	print_floor(int lines, int symbols, int spaces, int door)
{
	int index;
	int c;
	int stars;
	int h;

	index = 1;
	if (door)
	{
		door = 4 - (lines - 2) % 2;
	}
	h = lines - (((lines - 2) - 1) / 2);
	while (index <= lines)
	{
		c = 0;
		while (c++ < spaces + lines - index)
		{
			ft_putchar(' ');
		}
		ft_putchar('/');
		stars = symbols - ((lines - index) * 2) - 2;
		print_stars(stars, index >= door && door != 0, lines - 2, index == h);
		ft_putchar('\\');
		ft_putchar('\n');
		index++;
	}
}

void	print_stars(int symbols, int door, int size, int handle)
{
	int c;

	c = 0;
	if (door == 0)
	{
		while (c++ < symbols)
		{
			ft_putchar('*');
		}
	}
	else
	{
		door = size;
		if (size % 2 == 0)
		{
			door = size - 1;
		}
		print_stars((symbols - door) / 2, 0, size, 0);
		print_door(door, handle, size);
		print_stars((symbols - door) / 2, 0, size, 0);
	}
}

void	print_door(int door, int handle, int size)
{
	int c;

	c = 0;
	if (handle == 0 || size < 5)
	{
		while (c < door)
		{
			ft_putchar('|');
			c++;
		}
	}
	else
	{
		while (c < door - 2)
		{
			ft_putchar('|');
			c++;
		}
		ft_putchar('$');
		ft_putchar('|');
	}
}

int main(void)
{
	
	sastantua(1);
	sastantua(3);
	sastantua(5);
	return(0);
}