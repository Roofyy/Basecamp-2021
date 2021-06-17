/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:33:23 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/08 19:50:11 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *last;

	if (!begin_list)
	{
		return (0);
	}
	last = begin_list;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}
