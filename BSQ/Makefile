# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsamoilo <nsamoilo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 08:23:07 by nsamoilo          #+#    #+#              #
#    Updated: 2021/06/16 10:00:03 by nsamoilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SOURCES = srcs/
HEADERS = includes/
FUNCTIONS = pre_error post_error main make_array print_output read_input result
FILES = $(patsubst %, $(SOURCES)%.c, $(FUNCTIONS))
OBJECTS = $(patsubst %, %.o, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(FILES) -I$(HEADERS)
	@gcc -Wall -Werror -Wextra $(OBJECTS) -I$(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
