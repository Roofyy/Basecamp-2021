/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:58:05 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/15 20:26:29 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		conversion(char *str)
{
	int nb;
	int decimal;

	decimal = 1;
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (decimal == 1 && *str != '0')
			decimal = 10;
		else
			nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb);
}

int		ft_atoi(char *str)
{
	int negative;

	negative = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	if (*str == '+')
		str++;
	return (conversion(str) * negative);
}
