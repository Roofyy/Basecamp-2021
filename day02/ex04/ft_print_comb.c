/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:34:57 by osergeev          #+#    #+#             */
/*   Updated: 2021/05/27 19:36:55 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char k);

void	ft_print_comb(void)
{
	int first_digit;
	int second_digit;
	int third_digit;

	first_digit = '/';
	while (first_digit++ < '7')
	{
		second_digit = first_digit;
		while (second_digit++ < '8')
		{
			third_digit = second_digit;
			while (third_digit++ < '9')
			{
				ft_putchar(first_digit);
				ft_putchar(second_digit);
				ft_putchar(third_digit);
				if (first_digit != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
