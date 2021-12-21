NAME = so_long

FLAGS = -Wall -Wextra -Werror

INCLUDE = -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRC = *.c

HEADER = so_long.h

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

$(OBJ): $(SRC)
	@gcc $(FALGS) -c $(SRC)

clean:
		 @rm -rf $(OBJ)

fclean:	 clean
		 @rm -rf $(NAME)

re:		 fclean all

.PHONY: clean fclean all re