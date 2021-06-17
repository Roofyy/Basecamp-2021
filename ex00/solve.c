/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:38:04 by okinnune          #+#    #+#             */
/*   Updated: 2021/06/06 19:10:26 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** attempt - Calls isplacementvalid, checks x & y & 3x3
**		   - Attempts to solve using recursively incrementing digit
**		   - Reset to -2 ( '.' ) and move back when digits unsuccessful
**	       - Return 0 if unsolvable
*/

int		attempt(int board[9][9], int iy, int ix)
{
	int try;

	try = 1;
	if (board[iy][ix] == -2)
	{
		while (try < 10)
		{
			if (isplacementvalid(board, iy, ix, try))
			{
				board[iy][ix] = try;
				if (solve(board, iy, ix + 1) == 1)
					return (1);
			}
			try++;
		}
		board[iy][ix] = -2;
	}
	return (0);
}

/*
** solve - When column reaches 9, reset to 0 and jump down a row
**		 - If solved, will print finished board
**		 - Begins attempting to solve when -2 ( '.' )
**		 - If unsolvable, returns 0
*/

int		solve(int board[9][9], int iy, int ix)
{
	int try;

	try = 1;
	if (ix > 8)
	{
		ix = 0;
		iy++;
	}
	if (iy == 9)
	{
		printboard(board);
		return (1);
	}
	if (board[iy][ix] != -2)
	{
		if (solve(board, iy, ix + 1))
		{
			return (1);
		}
		return (0);
	}
	return (attempt(board, iy, ix));
	return (0);
}
