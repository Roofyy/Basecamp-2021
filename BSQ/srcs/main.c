/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 07:29:04 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/06/16 16:32:21 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_allocate(int height, int length)
{
	int i;
	int **clone_array;

	i = 0;
	clone_array = malloc(height * sizeof(int*));
	while (i < height)
	{
		clone_array[i] = malloc(length * sizeof(int));
		i++;
	}
	return (clone_array);
}

void	free_array(char **array, int **matrix)
{
	int i;

	i = 0;
	while (i < g_lines)
	{
		free(array[i]);
		i++;
	}
	free(array);
	i = 0;
	while (i < g_lines)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int		solve_map(char *filename, int index)
{
	char		*string;
	char		**matrix;
	int			**array;
	t_result	result;

	string = read_input(filename);
	if (index > 1)
		write(1, "\n", 1);
	if (!string || pre_error(string) || post_error(string))
	{
		write(2, ERROR, 10);
		return (1);
	}
	matrix = make_array(string);
	array = ft_allocate(g_lines, g_chars);
	result = find_result(matrix, g_lines, g_chars, array);
	print_output(matrix, result);
	free_array(matrix, array);
	free(string);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			solve_map(argv[i], i);
			i++;
		}
	}
	else
		solve_map("", 1);
	return (0);
}
