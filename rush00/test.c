/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thduong <thduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:23:21 by thduong           #+#    #+#             */
/*   Updated: 2021/05/30 11:08:41 by thduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void rush (int x, int y);
void ft_putchar(char c);

int	main(void)
{
	int x;
	int y;

	x = 10;
	while (--x > -2)
	{
		y = 6;
		while (--y >-2){
			printf("x: %d, y: %d\n", x, y);
			rush(x, y);
			ft_putchar('\n');
		}
	}
	return (0);
}




