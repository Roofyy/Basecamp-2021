/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:31:56 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/06/16 16:16:45 by osergeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ERROR "map error\n"

typedef struct	s_result
{
	int			x;
	int			y;
	int			size;
}				t_result;

int				g_lines;
int				g_chars;
int				g_empty;
int				g_obstacle;
int				g_full;

char			**make_array(char *str);
char			*read_input(char *filename);
t_result		find_result(char **array, int height, int length, int **c);
void			print_output(char **matrix, t_result res);
int				pre_error(char *str);
int				post_error(char *str);

#endif
