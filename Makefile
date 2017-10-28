
NAME = wolf3d

SRC 	= 		src/main.c \
				src/parsing.c \
				src/set.c \
				src/hooks.c \
				src/draw.c \
				src/loop.c \
				src/raycasting.c \
				src/move.c

GREEN = \033[32m
RED = \033[31m
CYAN = \033[36m
BLUE = \033[34m
YELLOW = \033[33m
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

OBJ 	= 	$(patsubst src/%.c, obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "$(BLUE)Compil Libft $(NORMAL)"
	@ make -C libft
	@ echo "$(GREEN)Libft compiled $(NORMAL)"
	@ echo "$(BLUE)Compil MLX $(NORMAL)"
	@ make -C $(MLX)
	@ echo "$(GREEN)MLX compiled $(NORMAL)"
	@ echo "$(GREEN)Objects created $(NORMAL)"
	@ gcc $(CFLAGS) $(OBJ) $(MLX_LNK) $(FT_INC) $(FT_LIB) -o $(NAME)
	@ echo "$(GREEN)Wolf3d compiled $(NORMAL)"

obj/%.o: src/%.c
	@ mkdir -p obj
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -rf $(OBJ)
	@ echo "$(RED)Objects Wolf3d destroyed $(NORMAL)"
	@ make -C $(FT) clean
	@ echo "$(RED)Objects Libft destroyed $(NORMAL)"
	@ make -C $(MLX) clean
	@ echo "$(RED)Objects MLX destroyed $(NORMAL)"

fclean: clean
	@ echo "$(YELLOW)Mlx.a was not destroyed, because MLX sucks and has no fclean rule...$(NORMAL)"
	@ rm -rf $(NAME)
	@ echo "$(RED)Wolf3d destroyed $(NORMAL)"
	@ make -C $(FT) fclean
	@ echo "$(RED)Libft.a destroyed $(NORMAL)"
re: fclean all

.PHONY: clean, fclean, re, all