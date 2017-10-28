
NAME = wolf3d

SRCS 	= 		main.c \
				parsing.c \
				set.c \
				hooks.c \
				draw.c \
				loop.c \
				raycasting.c \
				move.c

GREEN = \033[32m
RED = \033[31m
NORMAL = \033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

MLX = ./minilibx_macos/
MLX_LIB = $(addprefix $(MLX),mlx.a))
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -l mlx -framework OpenGl -framework AppKit

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

SRC 	= 	$(addprefix $(SRCDIR),$(SRCS))
OBJ 	= 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@ make -C libft
	@ echo "$(GREEN)Libft compiled $(NORMAL)"
	@ make -C $(MLX)
	@ echo "$(GREEN)MLX compiled $(NORMAL)"
	@ gcc $(CFLAGS) -c $(FT_INC) $(SRC)
	@ echo "$(GREEN)Objects created $(NORMAL)"
	@ gcc $(CFLAGS) $(OBJ) $(MLX_LNK) $(FT_INC) $(FT_LIB) -o $(NAME)
	@ echo "$(GREEN)Wolf3d compiled $(NORMAL)"

clean:
	@ rm -rf $(OBJ)
	@ echo "$(RED)Objects Wolf3d destroyed $(NORMAL)"
	@ make -C $(FT) clean
	@ echo "$(RED)Objects Libft destroyed $(NORMAL)"
	@ make -C $(MLX) clean
	@ echo "$(RED)Objects MLX destroyed $(NORMAL)"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "$(RED)Wolf3d destroyed $(NORMAL)"
	@ make -C $(FT) fclean
	
re: fclean all

.PHONY: clean, fclean, re, all