/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:37:47 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/11 19:12:23 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	void	*result;

	result = NULL;
	if (root->left)
		result = btree_search_item(root->left, data_ref, cmpf);
	if (!result && cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (!result && root->right)
		result = btree_search_item(root->right, data_ref, cmpf);
	return (result);
}
