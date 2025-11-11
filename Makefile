# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 11:10:25 by gpollast          #+#    #+#              #
#    Updated: 2025/11/11 11:57:08 by gpollast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3D

SRCS =	src/main.c \
        src/parse/parse.c

OBJ_DIR = obj
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -I./minilibx-linux -g

# Minilibx on Linux
MLX_DIR = minilibx-linux
MLX_REPO = https://github.com/42paris/minilibx-linux.git
MLX_FLAGS = -L./$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft

all: minilibx libft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Removed executable $(NAME)"
	@echo "Removed folder $(MLX_DIR)"

re: fclean all

minilibx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning $(MLX_REPO)..."; \
		git clone $(MLX_REPO); \
	else \
		echo "$(MLX_DIR) already exists, skipping clone."; \
	fi
	@echo "Building $(MLX_DIR)..."
	@$(MAKE) -C $(MLX_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re minilibx libft
