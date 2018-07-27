# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/07/25 16:20:15 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dskrypny.filler

SOURCE = main.c \
		 reader.c \
		 finder.c \
		 checker.c 

VISUAL_NAME = vm

VISUAL = visualizer.c \

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make re -C libft/
	@gcc $(FLAGS) $(SOURCE) -o $(NAME) $(LIB)
	@echo "filler compiled"

visual:
	gcc $(FLAGS) $(VISUAL) -o $(VISUAL_NAME) $(LIB) -lmlx -lncurses -framework Appkit -framework OpenGL 
	@echo "visualizer compiled"

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(VISUAL_NAME)


re: fclean all
