/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:14:29 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/03 14:28:29 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*target;

	i = 0;
	while (src[i])
	{
		i++;
	}
	target = malloc(sizeof(src) * i);
	i = 0;
	if (target == NULL)
	{
		return (0);
	}
	else
	{
		while (src[i])
		{
			target[i] = src[i];
			i++;
		}
		target[i] = '\0';
		return (target);
	}
}
