NAME = so_long

FLAGS = -Wall -Wextra -Werror -MD

INCLUDE = -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRC = filler_map.c				\
	  ft_itoa.c					\
	  get_next_line.c			\
	  get_next_line_utils.c		\
	  handler_key_event.c		\
	  init_img.c				\
	  main.c					\
	  parsing_map.c				\
	  so_long.c					\
	  valid_map.c

HEADER = so_long.h

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC)

clean:
		 @rm -rf $(OBJ) *.d

fclean:	 clean
		 @rm -rf $(NAME) *.d

re:		 fclean all

.PHONY: clean fclean all re