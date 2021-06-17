/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:10:42 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/11 19:12:53 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int i;
	int j;

	if (!root)
		return (0);
	i = btree_level_count(root->left);
	j = btree_level_count(root->right);
	if (i < j)
	{
		return (j + 1);
	}
	else
	{
		return (i + 1);
	}
}
