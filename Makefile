# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/07/08 20:38:15 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dskrypny.filler

SOURCE = main.c \
		 reader.c

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) $(SOURCE) -o $(NAME) $(LIB)
	@echo "filler compiled"

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
