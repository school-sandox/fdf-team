# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 16:49:15 by jmacgyve          #+#    #+#              #
#    Updated: 2019/08/21 20:19:50 by ycorrupt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = $(wildcard *.c)

OBJ = $(wildcard *.o)

INC = ./libft

LIBRARY = libft

$(NAME): $(SRC)
	gcc -c $(SRC) -I $(INC) 
	gcc $(SRC) -o $(NAME) -I $(INC) -L ./$(LIBRARY) -lft  -lmlx -framework OpenGL -framework Appkit 
	make -C $(LIBRARY) 

all:$(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBRARY) clean

fclean: clean 
	rm -f $(NAME)

re: fclean all
