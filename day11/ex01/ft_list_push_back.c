/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:13:11 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/10 08:04:12 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *element;

	if (*begin_list)
	{
		element = *begin_list;
		while (element->next)
		{
			element = element->next;
		}
		element->next = ft_create_elem(data);
	}
	else
	{
		*begin_list = ft_create_elem(data);
	}
}

int main(void)
{
    t_list *list;
    t_list *list2;

    list = NULL;
    list = ft_create_elem("00");
    list2 = ft_create_elem("01");
    list->next = list2;
    ft_list_push_back(&list, "02");
    ft_list_push_back(&list, "03");
    ft_list_push_back(&list, "04");
    while (list)
    {
        printf("%s\n", list->data);
        list = list->next;
    }
    return (0);
}