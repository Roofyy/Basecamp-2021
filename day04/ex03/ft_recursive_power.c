/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:58:42 by osergeev          #+#    #+#             */
/*   Updated: 2021/05/29 16:59:34 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (!nb || power < 0)
	{
		return (0);
	}
	if (!power)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
