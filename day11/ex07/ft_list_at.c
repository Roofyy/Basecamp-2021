/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:19:14 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/09 17:35:44 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!begin_list)
	{
		return (NULL);
	}
	while (begin_list)
	{
		if (i == nbr)
		{
			return (begin_list);
		}
		begin_list = begin_list->next;
		i++;
	}
	return (NULL);
}
