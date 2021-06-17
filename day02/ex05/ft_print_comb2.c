/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:10:14 by osergeev          #+#    #+#             */
/*   Updated: 2021/05/27 20:31:12 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char k);

void	ft_print_comb2(void)
{
	int	digit_one;
	int	digit_two;

	digit_one = 0;
	digit_two = 0;
	while (digit_one < 100)
	{
		digit_two = digit_one + 1;
		while (digit_two < 100)
		{
			ft_putchar(digit_one / 10 + '0');
			ft_putchar(digit_one % 10 + '0');
			ft_putchar(' ');
			ft_putchar(digit_two / 10 + '0');
			ft_putchar(digit_two % 10 + '0');
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			digit_two++;
		}
		digit_one++;
	}
}
