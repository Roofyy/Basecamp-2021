/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:54:48 by okinnune          #+#    #+#             */
/*   Updated: 2021/06/06 17:33:13 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** isinbox - ensures that no 3x3 square contains a duplicate
**		   - increments from first 3x3 on the board
** 		   - called within isplacementvalid
**		   - returns 1 if true
*/

int		isinbox(int board[9][9], int boxrow, int boxcol, int n)
{
	int		row;
	int		col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (board[col + boxcol][row + boxrow] == n)
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

/*
** isplacementvalid - scans x and y axis for duplicate digits
**					- using inbox & modulo calc to find within 3x3 range
**					- returns 1 if true
*/

int		isplacementvalid(int board[9][9], int yp, int xp, int val)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (board[i][xp] + '0' != '.' && board[i][xp] == val)
			return (0);
		if (board[yp][i] + '0' != '.' && board[yp][i] == val)
			return (0);
		i++;
	}
	if (val != -2 && isinbox(board, xp - xp % 3, yp - yp % 3, val) == 1)
		return (0);
	return (1);
}
