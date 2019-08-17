# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmacgyve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 16:49:15 by jmacgyve          #+#    #+#              #
#    Updated: 2019/08/17 16:49:17 by jmacgyve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = $(wildcard *.c)

OBJ = $(SRCS:.c=.o)

INC = libft/includes

LIBRARY = libft

$(NAME): $(SRC)
	gcc -o $(NAME) $(SRC) -I $(INC) -L ./$(LIBRARY) -lft  -lmlx -framework OpenGL -framework Appkit 
	make -C $(LIBRARY) 

all:$(NAME)

clean:
	rm -f *.o
	make -C $(LIBRARY) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
	gcc -c  $(SRC) -I $(INC)
