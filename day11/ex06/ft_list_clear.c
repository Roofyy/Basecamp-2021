/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:03:11 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/09 17:19:53 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *var;
	t_list *tmp;

	tmp = 0;
	var = begin_list[0];
	while (var)
	{
		tmp = var;
		free(var);
		var = tmp->next;
	}
	*begin_list = NULL;
}
