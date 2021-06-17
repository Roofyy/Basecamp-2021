/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:41:17 by osergeev          #+#    #+#             */
/*   Updated: 2021/06/03 19:50:11 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	char	*var;
	char	*sec_var;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (++i < argc && (sec_var = argv[i]))
		while (*sec_var++)
			++count;
	var = malloc(count * sizeof(char));
	if (!var)
		return (NULL);
	sec_var = var;
	i = 0;
	while (++i < argc)
	{
		while (*argv[i])
			*sec_var++ = *argv[i]++;
		if (i < argc - 1)
			*sec_var++ = '\n';
		else
			*sec_var++ = '\0';
	}
	return (var);
}
