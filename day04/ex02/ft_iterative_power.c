/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:54:19 by osergeev          #+#    #+#             */
/*   Updated: 2021/05/29 20:20:10 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int res;
	int i;

	res = 1;
	i = 0;
	if (power < 0)
	{
		return (0);
	}
	while (i++ < power)
	{
		res = res * nb;
	}
	return (res);
}
