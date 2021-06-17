/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:41:42 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/06/16 09:56:28 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	rep_ch(int g_full, int g_obstacle, int g_empty)
{
	if (g_full == g_obstacle || g_obstacle == g_empty || g_empty == g_full)
	{
		return (1);
	}
	return (0);
}

int	get_number(char *str)
{
	int index;
	int number;

	index = 0;
	number = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= '0' && str[index] <= '9')
			number = number * 10 + (str[index] - '0');
		else
			return (0);
		index++;
	}
	return (number);
}

int	check_first_line(char *str)
{
	int		i;
	int		n;
	char	*lines;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	g_full = str[i - 1];
	g_obstacle = str[i - 2];
	g_empty = str[i - 3];
	if (rep_ch(g_full, g_obstacle, g_empty))
		return (1);
	lines = malloc(sizeof(char) * i);
	n = 0;
	while (n < i - 3)
	{
		lines[n] = str[n];
		n++;
	}
	lines[n] = '\0';
	g_lines = get_number(lines);
	if (g_lines < 1)
		return (1);
	free(lines);
	return (0);
}

int	pre_error(char *str)
{
	if (check_first_line(str))
		return (1);
	return (0);
}
