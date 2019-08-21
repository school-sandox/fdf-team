# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 19:31:35 by ycorrupt          #+#    #+#              #
#    Updated: 2019/08/21 19:59:54 by ycorrupt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

FLAGS = -Wall -Wextra -Werror

INC = includes/libft.h

OBJC = $(SRC:.c=.o)

$(NAME): $(OBJC)
	ar rc $(NAME) $(OBJC)

all:$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJC): $(SRC)
	gcc -c $(FLAGS) $(SRC) -I $(INC)