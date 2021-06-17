/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:02:07 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/16 16:13:30 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	count_chars(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	error_line(char *string)
{
	int n_row;
	int i;

	n_row = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
		{
			n_row++;
		}
		i++;
	}
	if (n_row != g_lines)
	{
		return (1);
	}
	return (0);
}

int	error_len(char *string)
{
	int i;
	int strlen;

	i = 1;
	while (string[i - 1] != '\n')
		i++;
	strlen = 0;
	while (string[i] != '\0')
	{
		if (string[i] != '\n')
		{
			strlen++;
		}
		if (string[i] == '\n')
		{
			if (strlen != g_chars)
			{
				return (1);
			}
			strlen = 0;
		}
		i++;
	}
	return (0);
}

int	error_symb(char *string)
{
	int i;
	int	empty;

	i = 0;
	while (string[i - 1] != '\n')
		i++;
	empty = 0;
	while (string[i] != '\0')
	{
		if (string[i] == g_empty)
			empty++;
		if (string[i] != g_empty && string[i] != g_obstacle
		&& string[i] != '\n')
		{
			return (1);
		}
		i++;
	}
	if (!empty)
	{
		return (1);
	}
	return (0);
}

int	post_error(char *str)
{
	while (str[0] != '\n' && str[0] != '\0')
		str++;
	str++;
	g_chars = count_chars(str);
	if (error_line(str))
		return (1);
	else if (error_len(str))
		return (1);
	else if (error_symb(str))
		return (1);
	else
		return (0);
}
