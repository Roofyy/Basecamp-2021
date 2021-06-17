/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:00:02 by thduong           #+#    #+#             */
/*   Updated: 2021/06/13 19:18:29 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('A');
	}
	if (x == 2)
	{
		ft_putchar('A');
		ft_putchar('A');
	}
	if (x >= 3)
	{
		ft_putchar('A');
		i = 1;
		while (i <= (x - 2))
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	middle_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('B');
		ft_putchar('\n');
	}
	if (x == 2)
	{
		ft_putchar('B');
		ft_putchar('B');
		ft_putchar('\n');
	}
	if (x >= 3)
	{
		ft_putchar('B');
		i = 1;
		while (i <= x - 2)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B');
		ft_putchar('\n');
	}
}

void	last_row(int x)
{
	int i;

	if (x == 1)
	{
		ft_putchar('C');
	}
	if (x == 2)
	{
		ft_putchar('C');
		ft_putchar('C');
	}
	if (x >= 3)
	{
		ft_putchar('C');
		i = 1;
		while (i <= x - 2)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('C');
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
		while (i <= y - 2)
		{
			middle_row(x);
			i++;
		}
		last_row(x);
	}
}

int		main(void)
{
	int x =1;
	int y =1;
	rush(x, y);
	return (0);
}
