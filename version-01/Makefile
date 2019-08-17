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
