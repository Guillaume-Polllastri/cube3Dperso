# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 11:10:25 by gpollast          #+#    #+#              #
#    Updated: 2025/11/10 11:17:02 by gpollast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3D

SRCS = main.c

OBJ_DIR = obj
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./minilibx-linux -g

# Link flags for minilibx on Linux
MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed executable $(NAME)"

re: fclean all

.PHONY: all clean fclean re
