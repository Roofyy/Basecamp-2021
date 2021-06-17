# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaavist <ahaavist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:37:24 by ahaavist          #+#    #+#              #
#    Updated: 2021/06/16 19:36:40 by ahaavist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

LIBRARY = libft.a

SRC_DIR = ./src

HEADER_DIR = ./includes

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/ft_atoi.c $(SRC_DIR)/get_x.c $(SRC_DIR)/get_y.c $(SRC_DIR)/get_eof.c $(SRC_DIR)/find_obs.c $(SRC_DIR)/find_pot.c $(SRC_DIR)/ringleader.c $(SRC_DIR)/ft_putchar.c
 
all: $(NAME)

$(NAME): lib_it
	gcc -Wall -Wextra -Werror -I$(HEADER_DIR) -o $(NAME) -L. -lft

lib_it: 
	gcc -Wall -Wextra -Werror -c -I$(HEADER_DIR) $(SRC)
	ar cr $(LIBRARY) main.o find_pot.o ft_atoi.o get_x.o get_y.o get_eof.o ringleader.o find_obs.o ft_putchar.o
	ranlib $(LIBRARY)

fclean: clean
	/bin/rm -f $(NAME)
	
clean:
	/bin/rm -f main.o ft_atoi.o get_x.o get_y.o get_eof.o find_obs.o ringleader.o find_pot.o ft_putchar.o libft.a

re: fclean all
