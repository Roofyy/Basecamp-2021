/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:34:50 by okinnune          #+#    #+#             */
/*   Updated: 2021/06/06 19:10:38 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** checkvalidinput: - Recieves the input from terminal
**				    - Ensures character is a digit or '.'
**					- No less than 17 starting hints in a sudoku
**					- No less than 9 lines of sudoku with 9 characters
**					- Returns 1 if true / valid
*/

int		checkvalidinput(char *argv[])
{
	int i;
	int ci;
	int digits;

	i = 1;
	digits = 0;
	while (i <= 9)
	{
		ci = 0;
		while (argv[i][ci] != '\0')
		{
			if ((argv[i][ci] < '1' || argv[i][ci] > '9') && argv[i][ci] != '.')
				return (0);
			if (argv[i][ci] > '0' && argv[i][ci] <= '9')
				digits++;
			ci++;
		}
		if (ci != 9)
			return (0);
		i++;
	}
	return ((digits >= 17) ? 1 : 0);
}

/*
** initboard - Establishes unfinished 9x9 board
**			 - If possible, will attempt to call solve function
**			 - Returns 0 if unsuccessful
*/

int		initboard(char *argv[])
{
	static int	board[9][9];
	int			ix;
	int			iy;

	ix = 0;
	iy = 0;
	while (iy < 9)
	{
		while (ix < 9)
		{
			if (isplacementvalid(board, iy, ix, argv[iy + 1][ix] - '0') == 0)
			{
				ft_putstr("Error\n");
				return (0);
			}
			board[iy][ix] = argv[iy + 1][ix] - '0';
			ix++;
		}
		ix = 0;
		iy++;
	}
	solve(board, 0, 0);
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc != 10)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (checkvalidinput(argv) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	initboard(argv);
	return (0);
}
