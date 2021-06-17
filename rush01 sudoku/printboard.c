/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:21:03 by okinnune          #+#    #+#             */
/*   Updated: 2021/06/07 07:37:07 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** printboard - The coordinating x & y axis of sudoku board
**			  - Prints 9x9 2-dimensional array
**			  - Executed within solve function
*/

void	printboard(int board[9][9])
{
	int ix;
	int iy;

	ix = 0;
	iy = 0;
	while (iy < 9)
	{
		while (ix < 9)
		{
			ft_putchar(board[iy][ix] + '0');
			if (ix != 8)
				ft_putchar(' ');
			ix++;
		}
		ft_putchar('\n');
		ix = 0;
		iy++;
	}
}
