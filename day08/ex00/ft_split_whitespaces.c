/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:36:38 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/04 19:51:31 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(char *str)
{
	int i;
	int count_word;
	int j;

	i = 0;
	j = 0;
	count_word = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 126 && !j)
		{
			j = 1;
			count_word++;
		}
		if (!(str[i] >= 33 && str[i] <= 126 && j))
		{
			j = 0;
		}
		i++;
	}
	return (count_word);
}

int		word_len(char *str, int i)
{
	int len;

	len = 1;
	while (!(str[i] >= 33 && str[i] <= 126 && str[i] != '\0'))
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		m;
	char	**words;

	i = 0;
	j = 0;
	words = (char**)malloc(sizeof(char*) * count_words(str) + 1);
	while (str[i] != '\0' && j < count_words(str))
	{
		m = 0;
		while (!(str[i] >= 33 && str[i] <= 126))
			i++;
		words[j] = (char*)malloc(sizeof(char) * word_len(str, i) + 1);
		while ((str[i] >= 33 && str[i] <= 126) && str[i] != '\0')
		{
			words[j][m++] = str[i++];
		}
		words[j][m] = '\0';
		j++;
	}
	words[j] = (char*)malloc(sizeof(char));
	words[j] = 0;
	return (words);
}
