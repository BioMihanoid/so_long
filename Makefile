NAME = so_long

FLAGS = -Wall -Wextra -Werror

INCLUDE = -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRC = src/*.c

HEADER = includes/so_long.h

OBJ = $(SRC:src/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)

clean:
		 @rm -rf $(OBJ)

fclean:	 clean
		 @rm -rf $(NAME)

re:		 fclean all

.PHONY: clean fclean all re