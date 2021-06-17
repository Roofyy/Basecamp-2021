# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osergeev <osergeev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 07:23:42 by osergeev          #+#    #+#              #
#    Updated: 2021/06/13 09:22:52 by osergeev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRCS = srcs/*.c

all:
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
