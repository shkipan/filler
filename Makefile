# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/07/20 20:02:05 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dskrypny.filler

SOURCE = main.c \
		 reader.c \
		 finder.c \
		 checker.c 

VISUAL_NAME = vm

VISUAL = visualizer/main.c \
		 visualizer/console.c

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) $(SOURCE) -o $(NAME) $(LIB) -lmlx -framework OpenGL -framework Appkit 
	@echo "filler compiled"

visual:
	gcc $(FLAGS) $(VISUAL) -o $(VISUAL_NAME) $(LIB)
	@echo "visualizer compiled"

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
