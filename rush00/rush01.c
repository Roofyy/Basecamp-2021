/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:47:48 by ekiuru            #+#    #+#             */
/*   Updated: 2021/06/13 07:00:30 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('/');
	}
	if (x == 2)
	{
		ft_putchar('/');
		ft_putchar('\\');
	}
	if (x >= 3)
	{
		ft_putchar('/');
		i = 1;
		while (i <= (x - 2))
		{
			ft_putchar('*');
			i++;
		}
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	middle_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('*');
	}
	if (x == 2)
	{
		ft_putchar('*');
		ft_putchar('*');
	}
	if (x >= 3)
	{
		ft_putchar('*');
		i = 1;
		while (i <= (x - 2))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('*');
	}
	ft_putchar('\n');
}

void	last_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('\\');
	}
	if (x == 2)
	{
		ft_putchar('\\');
		ft_putchar('/');
	}
	if (x >= 3)
	{
		ft_putchar('\\');
		i = 1;
		while (i <= (x - 2))
		{
			ft_putchar('*');
			i++;
		}
		ft_putchar('/');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;

	if (y == 1)
	{
		first_row(x);
	}
	if (y == 2)
	{
		first_row(x);
		last_row(x);
	}
	if (y >= 3)
	{
		first_row(x);
		i = 1;
		while (i <= (y - 2))
		{
			middle_row(x);
			i++;
		}
		last_row(x);
	}
}
