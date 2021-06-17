/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:37:02 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/09 17:41:17 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*old;
	t_list	*fut;
	t_list	*now;

	old = 0;
	fut = 0;
	now = *begin_list;
	while (now)
	{
		fut = now->next;
		now->next = old;
		old = now;
		now = fut;
	}
	*begin_list = old;
}
