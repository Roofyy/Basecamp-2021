/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:33:23 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/08 19:54:01 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*var;

	i = 0;
	if (ac <= 0)
	{
		return (NULL);
	}
	var = NULL;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = var;
		var = list;
		i++;
	}
	return (list);
}
