/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:44:31 by ekiuru            #+#    #+#             */
/*   Updated: 2021/06/13 07:00:27 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_or_last_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('o');
	}
	if (x == 2)
	{
		ft_putchar('o');
		ft_putchar('o');
	}
	if (x >= 3)
	{
		ft_putchar('o');
		i = 1;
		while (i <= (x - 2))
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	middle_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('|');
	}
	if (x == 2)
	{
		ft_putchar('|');
		ft_putchar('|');
	}
	if (x >= 3)
	{
		ft_putchar('|');
		i = 1;
		while (i <= (x - 2))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;

	if (y == 1)
	{
		first_or_last_row(x);
	}
	if (y == 2)
	{
		first_or_last_row(x);
		first_or_last_row(x);
	}
	if (y >= 3)
	{
		first_or_last_row(x);
		i = 1;
		while (i <= (y - 2))
		{
			middle_row(x);
			i++;
		}
		first_or_last_row(x);
	}
}

int	main(void)
{
	int x;
	int y;

	x = 10;
	while (--x > -2)
	{
		y = 6;
		while (--y >-2){
			printf("x: %d, y: %d\n", x, y);
			rush(x, y);
			ft_putchar('\n');
		}
	}
	return (0);
}
