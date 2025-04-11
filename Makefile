LIB = ar rcs
RM = rm -f

CC = gcc

BLUE   = \033[34m
RESET  = \033[0m

CCFLAGS = -Wall -Wextra -Werror -g3 -lm -L./minilibx-linux -lXext -lX11 -lm -lz

SRC_DIR = src

SRC = so_long.c map.c map_utils.c mlx1.c moves.c\

OBJ = $(SRC:.c=.o)

INCLUDE = so_long.h

NAME = so_long

LIBFTA = Helicopter/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -I/Helicopter/libft.h -I/usr/include -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd Helicopter && make
	@$(CC) $(CCFLAGS) $(OBJ) -I./so_long.h -I /libft/libft.h minilibx-linux/libmlx_Linux.a $(LIBFTA) -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(BLUE)        ||>>    $(BLUE)so_long compiled!!    <<||$(RESET)"

clean:
	@$(RM) $(OBJ)
	@cd Helicopter && make clean

fclean:
	@$(RM) $(NAME) $(OBJ)
	@cd Helicopter && make fclean

re: fclean all

.PHONY: all clean fclean re