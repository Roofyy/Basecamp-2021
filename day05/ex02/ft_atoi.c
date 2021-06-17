/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:27:16 by osergeev          #+#    #+#             */
/*   Updated: 2021/05/31 16:36:11 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	spec_symb(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		neg;
	int		res;

	neg = 1;
	res = 0;
	i = spec_symb(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg = neg * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = res * neg;
	return (res);
}
