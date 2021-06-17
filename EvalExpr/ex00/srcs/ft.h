/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 07:23:26 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/13 13:59:45 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		expressions(int num1, int num2, char sign);
char	*remove_whitespaces(char *str);
int		is_it_parentheses(char **str);
int		priority_expression(char **str);
int		all_expression(char **str);
int		eval_expr(char *str);

#endif
