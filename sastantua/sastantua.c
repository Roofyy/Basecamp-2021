/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:03:29 by osergeev          #+#    #+#             */
/*   Updated: 2021/05/30 20:49:32 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_lines(int star, int space)
{
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
	}
	ft_putchar('/');
	while (star > 0)
	{
		ft_putchar('*');
		star--;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int floor = 1;
	int tot_row=0;
	int nr=0;
	int ns=0;
	int star;
	while(floor <= size)
	{	
		tot_row = tot_row+floor+3;
		floor++;
	}
	floor = 1;
	while(floor <= size)
	{	
		
		int row_num = floor+2;
		
		if (floor == 1)
		{
			int row = 0;
		while( row<row_num)
		{
			
			star = (2*row)+1;
			int space = tot_row - nr-((floor+6)/2);
			//printf("%d %d %d", symb, space, star);
			first_lines(star, space);
			row++;
			nr++;
		}
		ns=star;
		}
		
		else {
			int row = 0;
			
			star = ns+(floor+5)/2;
			while( row<row_num)
				{
			
			int space = tot_row - nr-(floor+5)/2;
			star=star+2;
			//printf("%d %d %d", symb, space, star);
			first_lines(star, space);
			row++;
			nr++;
			//printf("%d\n", star);
			ns=star;
				}
				
			}	
				
	floor++; 	
	}
}

int main(void)
{
	sastantua(4);
	return(0);
}