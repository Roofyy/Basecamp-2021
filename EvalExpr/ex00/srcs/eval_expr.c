/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 07:21:33 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/13 14:06:26 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*remove_whitespaces(char *str)
{
	int		previous;
	int		current;
	char	*str2;

	previous = 0;
	current = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[previous] != '\0')
	{
		if (str[previous] != ' ')
		{
			str2[current] = str[previous];
			current++;
		}
		previous++;
	}
	str2[current] = '\0';
	return (str2);
}

int		is_it_parentheses(char **str)
{
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	if ((*str)[0] == '+' || (*str)[0] == '-')
	{
		if ((*str)[0] == '-')
			sign = -1;
		*str = *str + 1;
	}
	if ((*str)[0] == '(')
	{
		*str = *str + 1;
		num = priority_expression(str);
		if ((*str)[0] == ')')
			*str = *str + 1;
		return (sign * num);
	}
	while ((*str)[0] >= '0' && (*str)[0] <= '9')
	{
		num = (num * 10) + (*str)[0] - '0';
		*str = *str + 1;
	}
	return (sign * num);
}

int		priority_expression(char **str)
{
	int		first_num;
	int		sec_num;
	char	operator;

	first_num = is_it_parentheses(str);
	while ((*str)[0] != '\0' && (*str)[0] != ')')
	{
		operator = (*str)[0];
		*str = *str + 1;
		if (operator == '+' || operator == '-')
			sec_num = all_expression(str);
		else
			sec_num = is_it_parentheses(str);
		first_num = expressions(first_num, sec_num, operator);
	}
	return (first_num);
}

int		all_expression(char **str)
{
	int		first_num;
	int		sec_num;
	char	operator;

	first_num = is_it_parentheses(str);
	while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%')
	{
		operator = (*str)[0];
		*str = *str + 1;
		sec_num = is_it_parentheses(str);
		first_num = expressions(first_num, sec_num, operator);
	}
	return (first_num);
}

int		eval_expr(char *str)
{
	str = remove_whitespaces(str);
	if (str[0] == '\0')
		return (0);
	return (priority_expression(&str));
}
