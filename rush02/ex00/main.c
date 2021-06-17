/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:37:14 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/14 06:09:07 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#define BUF_SIZE 8192
 
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n && ((s1[i] == '\0' && s2[i] != '\0') ||
				(s2[i] == '\0' && s1[i] != '\0')))
		return (s1[i] - s2[i]);
	return (0);
}

char *ft_strcpy(char *dest, char *src){
int i=0;
while (src[i]!='\0'){
	dest[i]=src[i];
	i++;
	}
dest[i]=src[i];
return(dest);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb < 10)
	{
		ft_putchar((char)(nb + '0'));
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((char)(nb % 10 + '0'));
	}
}


int	main(void)
{
	char save_input[8192];
	char i;
	char input;
	int width;
	int heigth;
	char type[30];
	int m=0;
	int j;
	
	width = 0;
	heigth = 0;
	i = 0;
	while (read(0, &input, 1))
	{
		if (input == '\n')
			heigth++;
		save_input[i] = input;
		if(input=='o'){
			m=1;
			ft_strcpy(type, "[rush-00]");
		}
		if(input=='/'){
			m=1;
			ft_strcpy(type, "[rush-01]");
		}
		if (input!='\n'){
		width++;
	}
		i++;


	}
	

	
if((save_input[i-2]==save_input[0]) && (width!=1 && heigth!=1) && m!=1){
	ft_strcpy(type, "[rush-04]");
}


//save_input[((width+1)*(heigth-1))]
		
	width = width/heigth;

	if(save_input[width-1]==save_input[0] && width!=1 && heigth!=1&& m!=1){
			ft_strcpy(type, "[rush-02]");
		}
	if(save_input[width-1]==save_input[i-2] && width!=1 && heigth!=1&& m!=1 ){
			ft_strcpy(type, "[rush-03]");
		}
	if(save_input[0]!=save_input[i-2] && width!=1 && heigth==1 && m!=1 ){
		ft_strcpy(type, "[rush-03]");
			j=0;
			while (type[j]!='\0'){
				ft_putchar(type[j]);
				j=j+1;
				}
			ft_putchar('[');
			ft_putnbr(width);
			ft_putchar(']');
			ft_putchar('[');
			ft_putnbr(heigth);
			ft_putchar(']');
			ft_putchar('|');
			ft_putchar('|');
			
			ft_strcpy(type, "[rush-04]");
			j=0;
			while (type[j]!='\0'){
				ft_putchar(type[j]);
				j=j+1;
				}
			ft_putchar('[');
			ft_putnbr(width);
			ft_putchar(']');
			ft_putchar('[');
			ft_putnbr(heigth);
			ft_putchar(']');
			ft_putchar('\n');
			return(0);
			
		}

	if(save_input[0]==save_input[i-2] && width!=1 && heigth==1 && m!=1 ){
			ft_strcpy(type, "[rush-02]");
			
		}
		
if(save_input[0]!=save_input[i-2] && width==1 && heigth!=1 && m!=1 ){
		ft_strcpy(type, "[rush-02]");
			j=0;
			while (type[j]!='\0'){
				ft_putchar(type[j]);
				j=j+1;
				}
			ft_putchar('[');
			ft_putnbr(width);
			ft_putchar(']');
			ft_putchar('[');
			ft_putnbr(heigth);
			ft_putchar(']');
			ft_putchar('|');
			ft_putchar('|');
			
			ft_strcpy(type, "[rush-04]");
			j=0;
			while (type[j]!='\0'){
				ft_putchar(type[j]);
				j=j+1;
				}
			ft_putchar('[');
			ft_putnbr(width);
			ft_putchar(']');
			ft_putchar('[');
			ft_putnbr(heigth);
			ft_putchar(']');
			ft_putchar('\n');
			return(0);
			
		}

	if(save_input[0]==save_input[i-2] && width==1 && heigth!=1 && m!=1 ){
			ft_strcpy(type, "[rush-03]");
			
		}

	if(width==1 && heigth==1 && m!=1 ){
		ft_strcpy(type, "[rush-02]");
			j=0;
			while (type[j]!='\0'){
				ft_putchar(type[j]);
				j=j+1;
				}
			ft_putchar('[');
			ft_putnbr(width);
			ft_putchar(']');
			ft_putchar('[');
			ft_putnbr(heigth);
			ft_putchar(']');
			ft_putchar('|');
			ft_putchar('|');
			ft_strcpy(type, "[rush-03]");
			j=0;
			while (type[j]!='\0'){
				ft_putchar(type[j]);
				j=j+1;
				}
			ft_putchar('[');
			ft_putnbr(width);
			ft_putchar(']');
			ft_putchar('[');
			ft_putnbr(heigth);
			ft_putchar(']');
			ft_putchar('|');
			ft_putchar('|');
			
			ft_strcpy(type, "[rush-04]");
			j=0;
			while (type[j]!='\0'){
				ft_putchar(type[j]);
				j=j+1;
				}
			ft_putchar('[');
			ft_putnbr(width);
			ft_putchar(']');
			ft_putchar('[');
			ft_putnbr(heigth);
			ft_putchar(']');
			ft_putchar('\n');
			return(0);
		}


	j=0;
	while (type[j]!='\0'){
		ft_putchar(type[j]);
		j=j+1;
	}
	ft_putchar('[');
	ft_putnbr(width);
	ft_putchar(']');
	ft_putchar('[');
	ft_putnbr(heigth);
	ft_putchar(']');
	ft_putchar('\n');

	return (0);
}
