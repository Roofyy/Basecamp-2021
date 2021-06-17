/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:29:10 by ahaavist          #+#    #+#             */
/*   Updated: 2021/06/16 19:36:19 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_atoi(char *str);
int		get_x(int fd);
int		get_y(int fd);
char	*get_eof(int fd);
int		**find_obs(int fd, char ob_char, int *axis);
int		**find_pot(int *axis, int **obs_pot);
int		*the_ringleader(int *axis, int **obs_pot, int *sqr);
void	ft_putchar(char c);

#endif
