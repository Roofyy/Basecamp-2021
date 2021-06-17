/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:11:04 by swilliam          #+#    #+#             */
/*   Updated: 2021/06/06 19:21:14 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*
** #include "header.h"
*/

/*
** #includes
*/

# include <unistd.h>

/*
** main.c
*/

int		solve(int board[9][9], int iy, int ix);
void	ft_putstr(char *str);
int		isplacementvalid(int board[9][9], int yp, int xp, int val);

/*
** solve.c
*/

int		isplacementvalid(int board[9][9], int yp, int xp, int val);
int		solve(int board[9][9], int iy, int ix);
void	printboard(int board[9][9]);

/*
** str_functions.c
*/

void	ft_putchar(char c);

#endif
